#pragma once
#include "stdafx.h"
#include "symbol.h"
#include "function.h"

namespace lispic
{
     class Builtin : public virtual Function
     {
	  std::string name;
     public:
	  Builtin(Symbols);
	  Symbol call(Symbols);
     };
}
