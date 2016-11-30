#pragma once
#include "stdafx.h"
#include "atom.h"
#include "types.h"
using std::string;

namespace lispic {

     extern Type;

     class Function {
	  std::map<string, Symbol> args;
	  Environment local_env;
	  S_expression form;
	  fun_t type;
     public:
	  S_expression call();
     };
     
}
