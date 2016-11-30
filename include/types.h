#pragma once

namespace lispic {
     enum atom_t {
	  NUMBER,
	  STRING,
     };

     enum symbol_t {
	  ATOM,
	  VARIABLE,
	  LIST,
	  FUNCTION,
     };

     enum fun_t {
	  SUBR, 		// built-in function
	  SPEC, 		// special form
	  EXPR,			// user-defined function
     };	  
}
