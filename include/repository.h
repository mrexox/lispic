/*
  Environments are responsible for setting the symbols correct way
  Also fulfill needed symbols as needed
*/

#pragma once
#include "stdafx.h"

// #include "value.h"
#include "symbol.h"
#include "environment.h"
#include "evaluator.h"

#include "function.h"
#include "user_func.h"
#include "builtin_func.h"
#include "special_func.h"

namespace lispic
{
     class Repository
     {
	  Repository();
	  ~Repository();
	  Repository(const Repository&) = delete;
	  Repository& operator=(const Repository&) = delete;
	  
	  typedef Environment<std::string, Symbol::Value> VariablesEnvironment;
	  typedef Environment<std::string, BuiltinFunction*> BuiltinMap;
	  typedef Environment<std::string, SpecialFunction*> SpecialMap;
	  typedef std::vector<VariablesEnvironment> Variables;
	  BuiltinMap builtins;
	  SpecialMap specials;
	  Variables variables;
	  
     public:
	  
	  static Repository& Get()
	       {
		    static Repository envs;
		    return envs;
	       }

	  Symbol::Value get(std::string);
	  bool has(std::string);
	  bool has_special(std::string);
	  Symbol::Value get_special(std::string);
	  void set(std::string, Symbol::Value);

	  friend Symbol set_var(Symbols&);
	  friend Symbol def(Symbols&);
	  friend Symbol lambda(Symbols&);
	  
     };
     // Specials
     Symbol set_var(Symbols&);
     Symbol def(Symbols&);
     Symbol lambda(Symbols&);
     
     // Builtins
     Symbol sum(Symbols&);
     Symbol print(Symbols&);
     Symbol println(Symbols&);
     Symbol concat(Symbols&);


}
