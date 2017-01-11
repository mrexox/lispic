#include "repository.h"

namespace lispic
{
     
     Repository::Repository()
     {
	  VariablesEnvironment ve;
	  ve["nil"] = Symbol::Value(false);
	  ve["t"] = Symbol::Value(true);
	  variables.push_back(ve);
	  
	  builtins["+"] = new BuiltinFunction(lib::sum);
	  builtins["-"] = new BuiltinFunction(lib::subtract);
	  builtins["*"] = new BuiltinFunction(lib::product);
	  builtins["/"] = new BuiltinFunction(lib::devide);
	  builtins["%"] = new BuiltinFunction(lib::modul);
	  builtins["null"] = new BuiltinFunction(lib::null);
	  builtins[">"] = new BuiltinFunction(lib::more);
	  builtins["print"] = new BuiltinFunction(lib::print);
	  builtins["println"] = new BuiltinFunction(lib::println);
	  builtins["concat"] = new BuiltinFunction(lib::concat);
	  builtins["set"] = new BuiltinFunction(lib::set);
	  builtins["not"] = new BuiltinFunction(lib::_not);
	  builtins["equal"] = new BuiltinFunction(lib::equal);
	  builtins["list"] = new BuiltinFunction(lib::list);
	  builtins["car"] = new BuiltinFunction(lib::car);
	  builtins["cdr"] = new BuiltinFunction(lib::cdr);
	  builtins["map"] = new BuiltinFunction(lib::map);
	  
	  
	  specials["def"] = new SpecialFunction(lib::def);
	  specials["lambda"] = new SpecialFunction(lib::lambda);
	  specials["if"] = new SpecialFunction(lib::if_statement);
	  specials["have"] = new SpecialFunction(lib::have);
	  specials["cycle"] = new SpecialFunction(lib::cycle);
	  specials["undef"] = new SpecialFunction(lib::undef);
     }

     Repository::~Repository()
     {
	  for(BuiltinMap::iterator p = builtins.begin();
	      p != builtins.end();
	      ++p)
	  {
	       if ( p->second ) delete p->second;
	  }

	  for(SpecialMap::iterator p = specials.begin();
	      p != specials.end();
	      ++p)
	  {
	       if ( p->second ) delete p->second;
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
	  if (builtins.has(name)) return Symbol::Value(builtins.get(name));
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
	  return builtins.has(name);
     }
     
     bool Repository::has_special(std::string name)
     {
	  SpecialMap::iterator p = specials.find(name);
	  return p != specials.end();
     }
     
     Symbol::Value Repository::get_special(std::string name)
     {
	  SpecialMap::iterator p = specials.find(name);
	  if (p != specials.end())
	  {
	       return Symbol::Value(p->second);
	  }
	  else return Symbol::Value();
     }
     
     void Repository::set(std::string name, Symbol::Value value)
     {
	  variables.back()[name] = value;
     }
}
