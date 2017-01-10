#include "symbol.h"

namespace lispic
{
     std::ostream& operator << (std::ostream& out, const Symbol& symbol)
     {
	  switch(symbol.type())
	  {
	  case NUMBER:
	       out << symbol._value.number();
	       break;
	  case STRING:
	       out << '\"' << symbol._value.string() << '\"';
	       break;
	  case FUNCTION:
	       out << "#<Function " + symbol.name() + ">";
	       break;
	  case T:
	       out << "t";
	       break;
	  case NIL:
	       out << "nil";
	       break;
	  case LIST:
	       out << "(";
	       for (Symbols::iterator p = symbol.value().list().begin();
		    p != symbol.value().list().end();
		    ++p)
	       {
		    out << *p;
		    if (p + 1 != symbol.value().list().end()) out << " ";
	       }
	       out << ")";
	       break;
	  default:
	       out << "!Error, not initialized symbol!";
	       break;
	  }
	  return out;

     }

     std::ostream& operator << (std::ostream& out, const Symbol::Value& value)
     {
	  switch(value.type())
	  {
	  case NUMBER:
	       out << value.number();
	       break;
	  case STRING:
	       out << value.string();
	       break;
	  case NIL:
	       out << "NIL";
	       break;
	  case T:
	       out << "T";
	       break;
	  default:
	       out << "#<Value: number=" << value.number()
		   << " string=" << value.string()
		   << " type=" << value.type();
	       break;
	  }
	  return out;
     }

     bool operator < (const Symbol::Value& v1, const Symbol::Value& v2)
     {
	  if (v1.type() == NUMBER)
	       return v1.number() < v2.number();
	  // may be changed to used with strings
	  return false;
     }
     
     bool operator == (const Symbol::Value& v1, const Symbol::Value& v2)
     {
	  if (v1.type() == NUMBER)
	       return v1.number() == v2.number();
	  // may be changed to used with strings
	  return false;
     }

     bool operator <= (const Symbol::Value& v1, const Symbol::Value& v2)
     {
	  if (v1.type() == NUMBER)
	       return v1.number() <= v2.number();
	  // may be changed to used with strings
	  return false;
     }
}
