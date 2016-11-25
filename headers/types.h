#pragma once
#include "stdafx"

namespace lispic {
     enum type {
	  SYMBOL, NUMBER, STRING, FUNCTION, CONS_CELL,
     };
     enum function_type {
	  USER, BUITIN, MACROS, BUILTINMACROS
     };
     class atom {
	  /* Atoms do all their work by themselves
	   * You just need to call atom1 + atom2 
	   * or concat( atom1, atom2 ) 
	   */
	  string svalue;
	  double dvalue;
	  type my_type;
	  void cast_values_or_die(atom& src);
     public:
	  friend atom& concat (atom& atom1, atom& atom2);
	  atom(string aname, string val) : svalue(val), my_type(STRING) {}
	  atom(string aname, double val) : dvalue(val), my_type(NUMBER) {}
	  atom& operator + (atom& another);
	  atom& operator - (atom& another);
	  atom& operator / (atom& another);
	  atom& operator % (atom& another);
	  atom& operator * (atom& another);
     };
     
     struct s_expression {};
     struct function {};
     struct cons_cell {};

     /* Exceptions */
     class bad_cast_to_string : std::exception {};
     class bad_cast_to_number : std::exception {};

     // Other functions
     atom& concat (atom& atom1, atom& atom2);
	  
}
