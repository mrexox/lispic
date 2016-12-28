/*
  Function can be either BuiltinFunction or UserFunction
  Builtin implements call() as c++ call
  User's implement call() as a srial calls of functions inside it
 */

#pragma once
#include "stdafx.h"
#incude "environment.h"

namespace lispic
{
     class Function
     {
     protected:
	  Environment local_env;
     public:
	  Fuction(Symbols);
	  virtual Symbol call(Symbols);
     };
}
