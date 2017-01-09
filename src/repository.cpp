#include "repository.h"

namespace lispic
{
     
     Repository::Repository()
     {
	  variables.push_back(VariablesEnvironment());
	  
	  builtins["sum"] = new BuiltinFunction(sum);
	  builtins["print"] = new BuiltinFunction(print);
	  builtins["println"] = new BuiltinFunction(println);
	  builtins["concat"] = new BuiltinFunction(concat);
	  
	  specials["set"] = new SpecialFunction(set_var);
	  // specials["def"] = new SpecialFunction(def);
	  // specials["lambda"] = new SpecialFunction(lambda);
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
	  return true;

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

     Symbol sum(Symbols& symbols)
     {
	  Number res = 0;
	  for (Symbols::const_iterator p = symbols.begin();
	       p != symbols.end();
	       ++p)
	  {
	       res += p->value().number();
	  }
	  return Symbol(std::to_string(res), Symbol::Value(res));
     }
     
     Symbol print(Symbols& symbols)
     {
	  for(Symbols::iterator p = symbols.begin();
	      p != symbols.end();
	      ++p)
	  {
	       std::cout << p->value();
	       if (p + 1 != symbols.end()) std::cout << ' ';
	  }
	  return Symbol();
     }

     Symbol println(Symbols& symbols)
     {
	  Symbol s = print(symbols);
	  std::cout << std::endl;
	  return s;
     }
     
     Symbol concat(Symbols& symbols)
     {
	  std::string res;
	  for (Symbols::const_iterator p = symbols.begin();
	       p != symbols.end();
	       ++p)
	  {
	       res += p->value().string();
	  }
	  return Symbol('\"' + res + '\"', Symbol::Value(res));
     }
     
     
     Symbol set_var(Symbols& symbols)
     {
	  for (Symbols::iterator p = symbols.begin();
	       p < symbols.end();
	       p += 2)
	  {
	       Symbol tmpsym = Evaluator::Get().eval( *(p+1) );
	       Repository::Get().variables.back()[p->name()] = tmpsym.value();
	  }
	  return symbols.back();
     }

     // Symbol def(Symbols& symbols){}
     // Symbol lambda(Symbols& symbols){}
	  /*
	    UserFunction with no name
	    (lambda (arg1 arg2 ...) (body...))
	    symbols:
	      symbols - args
	      symbols - body:
	        
	   */
}
