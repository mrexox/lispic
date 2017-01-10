/*
  Function can be either BuiltinFunction or UserFunction
  Builtin implements call() as c++ call
  User's implement call() as a srial calls of functions inside it
 */

#pragma once
#include "stdafx.h"
#include "symbol.h"
#include "environment.h"

namespace lispic
{
     class Symbol;
     typedef std::vector<Symbol> Symbols;
     
     class Function
     {
     public:
	  virtual Symbol call(Symbols& args) = 0;
	  virtual ~Function() {}
     };

     class call_error : public lispic_error
     {
     public:
	 call_error(const std::string msg) : lispic_error(msg) {}
     };
}
