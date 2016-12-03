#include "stdafx.h"
#include "s_expression.h"
//#include <list>

namespace lispic {

     class List{
	  Symbol* first;
	  List* rest;
	  class iterator 
	  {
	       iterator& operator++(int);
	       iterator& operator++();
	  };
     public:
	  List(Reader reader, string string);
	  List(List*);
	  
	  Symbol& car();
	  List& cdr();
	  
	  iterator begin();
	  iterator end();
     };
}
