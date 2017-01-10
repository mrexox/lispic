#pragma once
#include "symbol.h"
#include "function.h"

namespace lispic
{
 
     
     class BuiltinFunction : public virtual Function
     {
	  typedef Symbol (*builtin)(Symbols&);
	  builtin function;
     public:
	  BuiltinFunction(builtin function)
	       : function(function) {}
	  Symbol call(Symbols& args)
	  {
	       return function(args);
	  }
     };
}
