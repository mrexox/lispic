#include "Atom.h"

using namespace lispic;
// Classes' methods
void 
Atom::cast_values_or_die(Atom& src) 
{
     if (type != NUMBER) {
	  try {
	       dvalue = std::stod(svalue);
	  } catch (std::invalid_argument e) {
	       throw bad_cast_to_number();
	  }
     }
     if (src.type != NUMBER) {
	  try {
	       src.dvalue = std::stod(src.svalue);
	  } catch (std::invalid_argument e) {
	       throw bad_cast_to_number();
	  }
     }
}

Atom& 
Atom::operator + (Atom& another) 
{
     cast_values_or_die(another);
     dvalue += another.dvalue;
     return *this;
}

Atom& 
Atom::operator - (Atom& another) 
{
     cast_values_or_die(another);
     dvalue -= another.dvalue;
     return *this;
}

Atom& 
operator / (Atom& another) 
{
     cast_values_or_die(another);
     dvalue /= another.dvalue;
     return *this;
}

Atom& 
operator % (Atom& another) 
{
     cast_values_or_die(another);
     dvalue %= another.dvalue;
     return *this;
}

Atom& 
operator * (Atom& another) 
{
     cast_values_or_die(another);
     dvalue *= another.dvalue;
     return *this;
}
// Exceptions' methods
// Other functions
Atom& 
concat (Atom& atom1, Atom& atom2) 
{
     atom1.svalue += atom2.svalue;
     return atom1;
}
