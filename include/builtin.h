#pragma once
#include "stdafx.h"
#include "symbol.h"
#include "function.h"

namespace lispic
{
     typedef Symbol (*buitin)(Symbols&);
     
     class Builtin : public virtual Function
     {
	  builtin function;	  
	  std::string name;
     public:
	  Builtin(builtin function)
	       : function(function) {}
	  Symbol call(Symbols&);
     };
}
