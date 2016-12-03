#pragma once
#include "stdafx.h"
#include "types.h"
#include "list.h"
#include "symbol.h"

namespace lispic {

     class S_expression {
	  s_type type;
	  List* list;
	  Symbol* symbol;
     public:
	  S_expression(List* list) 
	       : list(list), type(LIST) {}
	  S_expression(Symbol* symbol) 
	       : symbol(symbol), type(SYMBOL) {}
	  ~S_expression();	// do we need this?
	  
	  List* getList() { return list; }
	  Symbol* getSymbol() { return symbol; }
     };

     S_expression funcall(List*);
}
