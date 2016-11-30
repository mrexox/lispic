#pragma once
#include "stdafx.h"
#include "types.h"

namespace lispic {

     extern Type;
     class S_expression {
	  Type type;
	  Symbol symbol;		// need to be realized
     };
//     typedef S_expression Cons_cell;
}
