#include "types.h"
namespace lispic {
     // Classes' methods
     void atom::cast_values_or_die(atom& src) {
	  if (my_type != NUMBER) {
	       try {
		    dvalue = std::stod(svalue);
	       } catch (std::invalid_argument e) {
		    throw bad_cast_to_number();
	       }
	  }
	  if (src.my_type != NUMBER) {
	       try {
		    src.dvalue = std::stod(src.svalue);
	       } catch (std::invalid_argument e) {
		    throw bad_cast_to_number();
	       }
	  }
     }
     atom& atom::operator + (atom& another) {
	  cast_values_or_die(another);
	  dvalue += another.dvalue;
	  return *this;
     }
     atom& atom::operator - (atom& another) {
	  cast_values_or_die(another);
	  dvalue -= another.dvalue;
	  return *this;
     }
     atom& operator / (atom& another) {
	  cast_values_or_die(another);
	  dvalue /= another.dvalue;
	  return *this;
     }
     atom& operator % (atom& another) {
	  cast_values_or_die(another);
	  dvalue %= another.dvalue;
	  return *this;
     }
     atom& operator * (atom& another) {
	  cast_values_or_die(another);
	  dvalue *= another.dvalue;
	  return *this
     }
     // Exceptions' methods
     // Other functions
     atom& concat (atom& atom1, atom& atom2) {
	  atom1.svalue += atom2.svalue;
	  return atom1;
     }
}
