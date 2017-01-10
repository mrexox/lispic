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
#include "lib.h"

namespace lispic
{
     class Repository
     {
	  Repository();
	  ~Repository();
	  Repository(const Repository&) = delete;
	  Repository& operator=(const Repository&) = delete;
	  typedef BuiltinFunction SpecialFunction;
	  
	  typedef Environment<std::string, Symbol::Value> VariablesEnvironment;
	  typedef Environment<std::string, BuiltinFunction*> BuiltinMap;
	  typedef Environment<std::string, SpecialFunction*> SpecialMap;
	  typedef std::vector<VariablesEnvironment> Variables;
	  BuiltinMap builtins;
	  SpecialMap specials;
	  Variables variables;
	  friend class UserFunction;
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

	  friend Symbol lib::set(Symbols&);
	  friend Symbol lib::def(Symbols&);
	  friend Symbol lib::lambda(Symbols&);
	  friend Symbol lib::have(Symbols&);
	  friend Symbol lib::cycle(Symbols&);
	  friend Symbol lib::undef(Symbols&);
     };

}
