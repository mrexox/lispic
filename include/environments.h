/*
  Environments are responsible for setting the symbols correct way
  Also fulfill needed symbols as needed
*/

#pragma once
#include "stdafx.h"
#include "symbol.h"
#include "environment.h"
#include "function.h"
#include "builtin.h"

namespace lispic
{
     class Environments
     {
	  Environments();
	  ~Environments() {}
	  Environments(const Environments&) {}
	  Environments& operator=(const Environments&) {}
	  
	  Environment<std::string, Function> builtins;
	  Environment<std::string, Function> user_defined;
	  Envirinment<std::string, Symbol> varibles;
	  
     public:
	  static Environments Get
	       {
		    static Environments envs;
		    return envs;
	       }
	  bool fulfill(Symbol&);
	  void set(std::string, Symbol);
	  friend Symbol def(Symbols&);
	  friend Symbol set(Symbols&);
     };
     
     Symbol sum(Symbols&);
     Symbol print(Symbols&);
     Symbol concat(Symbols&);
     Symbol def(Symbols&);
     Symbol set(Symbols&);
     Symbol lambda(Symbols&);
}
