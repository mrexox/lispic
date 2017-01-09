#pragma once
#include "stdafx.h"
#include "symbol.h"
#include "function.h"

namespace lispic
{
     typedef Symbol (*builtin)(Symbols&);
     
     class BuiltinFunction : public virtual Function
     {
	  builtin function;
	  std::string name;
     public:
	  BuiltinFunction(builtin function)
	       : function(function) {}
	  Symbol call(Symbols& args)
	  {
	       return function(args);
	  }
     };
}
