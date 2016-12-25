#pragma once
#include "stdafx.h"
#include "symbol.h"

namespace lispic
{
     class Environment 
     {
	  
     public:
	  Symbol get(Symbol);
	  Symbol set(Symbol);
	  bool fulfill(Symbol&);
     };     
}
