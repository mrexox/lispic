#include "symbol.h"

namespace lispic
{
     std::ostream& operator << (std::ostream& out, const Symbol& symbol)
     {
	  return out << symbol._value;

     }

     std::ostream& operator << (std::ostream& out, const Symbol::Value& value)
     {
	  switch(value._type)
	  {
	  case NUMBER:
	       out << value._number;
	       break;
	  case STRING:
	       out << value._string;
	       break;
	  case NIL:
	       out << "NIL";
	       break;
	  case T:
	       out << "T";
	       break;
	  case LIST:
	       out << "(";
	       for (Symbols::const_iterator p = value._list.begin();
		    p != value._list.end();
		    ++p)
	       {
		    out << *p;
		    if (p + 1 != value._list.end()) out << " ";
	       }
	       out << ")";
	       break;
	  default:
	       break;
	  }
	  return out;
     }

     bool operator < (const Symbol::Value& v1, const Symbol::Value& v2)
     {
	  if (v1.type() == NUMBER)
	       return v1.number() < v2.number();
	  // may be changed to used with strings
	  switch(v1.type())
	  {
	  case NUMBER:
	       return v1.number() <= v2.number();
	       break;
	  case STRING:
	       return v1.string() <= v2.string();
	       break;
	  case T:
	  case NIL:
	       return false;
	       break;
	  case LIST:
	       // Not Implemented yet
	  default:
	       break;
	  }
	  return false;
     }
     
     bool operator == (const Symbol::Value& v1, const Symbol::Value& v2)
     {
	  if (v1.type() != v2.type()) return false;
	  
	  switch(v1.type())
	  {
	  case NUMBER:
	       return v1.number() == v2.number();
	       break;
	  case STRING:
	       return v1.string() == v2.string();
	       break;
	  case T:
	  case NIL:
	       return true;
	       break;
	  case LIST:
	       // Not Implemented yet
	  default:
	       break;
	  }
	  return false;
     }

     bool operator != (const Symbol::Value& v1, const Symbol::Value& v2)
     {
     	  return !(v1 == v2);
     }


     bool operator <= (const Symbol::Value& v1, const Symbol::Value& v2)
     {
	  if (v1.type() == NUMBER)
	       return v1.number() <= v2.number();
	  // may be changed to used with strings
	  return false;
     }
}
