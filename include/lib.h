#include "repository.h"

namespace lispic
{
     namespace lib
     {
	  // Specials
	  Symbol set(Symbols&);
	  Symbol def(Symbols&);
	  Symbol lambda(Symbols&);
	  Symbol if_statement(Symbols&);
	  Symbol have(Symbols&);
     
	  // Builtins
	  Symbol sum(Symbols&);
	  Symbol print(Symbols&);
	  Symbol println(Symbols&);
	  Symbol concat(Symbols&);
	  Symbol subtract(Symbols&);
	  Symbol product(Symbols&);
	  Symbol devide(Symbols&);
	  Symbol null(Symbols&);
	  Symbol more(Symbols&);
	  Symbol less(Symbols&);
	  Symbol equal(Symbols&);
	  Symbol _not(Symbols&);
     }
}
