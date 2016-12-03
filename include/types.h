#pragma once

namespace lispic {
     enum s_type {
	  LIST,
	  SYMBOL,
     };

     enum atom_type {
	  NUMBER,
	  STRING,
     };

     enum symbol_type {
	  ATOM,
	  VARIABLE,
	  LIST,
	  FUNCTION,
     };

     enum fun_type {
	  SUBR, 		// built-in function
	  SPEC, 		// special form
	  EXPR,			// user-defined function
     };	  
}
