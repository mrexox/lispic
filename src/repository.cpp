#include "repository.h"
namespace lispic
{
     
     Repository::Repository()
     {
	  VariablesEnvironment ve;
	  ve["nil"] = Symbol::Value(false);
	  ve["t"] = Symbol::Value(true);
	  variables.push_back(ve);
	  
	  init_functions({
		    // Builtins
		    {"+", lib::sum }, {"-", lib::subtract },
		    {"*", lib::product }, {"/", lib::devide },
		    {"%", lib::modul }, {"null", lib::null },
		    {">" , lib::more }, {"print", lib::print },
		    {"println", lib::println }, {"concat", lib::concat },
		    {"set", lib::set }, {"not", lib::_not },
		    {"equal", lib::equal }, {"list", lib::list },
		    {"car", lib::car }, {"cdr", lib::cdr },
		    {"map", lib::map }, {"load", lib::load},

		    // Specials
		    {"def", lib::def }, {"lambda", lib::lambda },
		    {"if", lib::if_statement }, {"have", lib::have },
		    {"cycle", lib::cycle }, {"undef", lib::undef },
		
			 });
	  
	  specials = {
	       "def", "lambda",
	       "if", "have",
	       "cycle", "undef",
	  };
     }
     
     Repository::~Repository()
     {
	  for(CompiledMap::iterator p = compiled.begin();
	      p != compiled.end();
	      ++p)
	  {
	       if ( p->second ) delete p->second;
	  }
     }

     void Repository::init_functions(const std::map<std::string, CompiledFunction::builtin>& base)
     {
	  for(std::map<std::string, CompiledFunction::builtin>::const_iterator p = base.begin();
	      p != base.end();
	      ++p)
	  {
	       compiled[p->first] = new CompiledFunction(p->second);
	  }
     }
     
     Symbol::Value Repository::get(std::string name)
     {
	  for(Variables::reverse_iterator p = variables.rbegin();
	      p != variables.rend();
	      ++p)
	  {
	       if (p->has(name)) return (*p)[name];
	  }
	  if (compiled.has(name)) return Symbol::Value(compiled.get(name));
	  return Symbol::Value(); // Get NIL and catch an error!
     }
     
     bool Repository::has(std::string name)
     {
	  for(Variables::reverse_iterator p = variables.rbegin();
	      p != variables.rend();
	      ++p)
	  {
	       if (p->has(name)) return true;
	  }
	  return compiled.has(name);
     }
     
     bool Repository::has_special(std::string name)
     {
	  Specials::iterator p = std::find(specials.begin(), specials.end(), name);
	  return p != specials.end();
     }
     
     void Repository::set(std::string name, Symbol::Value value)
     {
	  variables.back()[name] = value;
     }
}
