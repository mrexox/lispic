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
	  case LIST:
	       break;
	  case NIL:
	       out << "nil";
	       break;
	  default:
	       out << "!Error, not initialized symbol!";
	       break;
	  }
	  return out;

     }

     std::ostream& operator << (std::ostream& out, const Symbol::Value& value)
     {
	  if (value.type() == NUMBER)
	       out << value.number();
	  else if (value.type() == STRING)
	       out << value.string();
	  else
	       out << "Unknown";
	  return out;
     }
}
