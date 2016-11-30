#pragma once
#include "types.h"

namespace lispic {
     class Atom {
	  /* Atoms do all their work by themselves
	   * You just need to call Atom1 + Atom2 
	   * or concat( Atom1, Atom2 ) 
	   * Can be constructed via Atom("hello");
	   *                        Atom(34);
	   */
	  string svalue;
	  double dvalue;
	  Type type;
	  void cast_values_or_die(Atom& src);
     public:
//	  Atom(Atom&);  // need it or not? ref in symbol.h
	  Atom(string val) : svalue(val), type(STRING) {}
	  Atom(double val) : dvalue(val), type(NUMBER) {} 
	  Atom& operator + (Atom& another);
	  Atom& operator - (Atom& another);
	  Atom& operator / (Atom& another);
	  Atom& operator % (Atom& another);
	  Atom& operator * (Atom& another);
	  Type get_type() { return type; }

	  friend Atom& concat (Atom& atom1, Atom& atom2);
     };
     
     /* Exceptions */
     class bad_cast_to_string : std::exception {};
     class bad_cast_to_number : std::exception {};

     // Other functions
     Atom& concat (Atom& atom1, Atom& atom2);
}
