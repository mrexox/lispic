#include "stdafx.h"
#include "s_expression.h"
#include <list>

namespace lispic {

     class List{
	  std::list<Symbol, S_expression> data;
     public:
	  S_expression& car();
	  List& cdr();
	  
     };
}
