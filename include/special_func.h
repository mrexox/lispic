#pragma once
#include "symbol.h"
#include "function.h"

namespace lispic
{
     class SpecialFunction : public Function
     {
	  typedef Symbol (*special)(Symbols&);
	  special function;
     public:
	  SpecialFunction(special function)
	       : function(function) {}
	  Symbol call(Symbols& args)
	       {
		    return function(args);
	       }
     };


}
