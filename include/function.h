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
