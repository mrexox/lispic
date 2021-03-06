#include "repository.h"
#include "reader.h"

namespace lispic
{
     namespace lib
     {
	  // Specials
	  Symbol set(Symbols&);
	  Symbol def(Symbols&);
	  Symbol undef(Symbols&);
	  Symbol lambda(Symbols&);
	  Symbol if_statement(Symbols&);
	  Symbol have(Symbols&);
	  Symbol cycle(Symbols&);
	  
	  // Builtins
	  Symbol sum(Symbols&);
	  Symbol modul(Symbols&);
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
	  Symbol equal(Symbols&);
	  Symbol load(Symbols&);
	  
	  // List's bultins
	  Symbol list(Symbols&);
	  Symbol car(Symbols&);
	  Symbol cdr(Symbols&);
	  Symbol map(Symbols&);
     }
}
