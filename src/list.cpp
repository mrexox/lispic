#include "list.h"

namespace lispic {
     List() {
	  symbol = NIL;
	  end = 0;
	  next = end;
     }
     List(List&);
     List(List&&);
     ~List();
     List& operator = (List&);
     Symbol& car() {
	  return symbol;	// must be used as reference
     }
     List& cdr();

}
