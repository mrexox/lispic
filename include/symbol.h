#pragma once
#include "atom.h"
#include "function.h"

namespace lispic {
     class Symbol {
	  Type type;
	  Atom value;
	  List list;
	  Function function;
     public:
	  Symbol(Atom a) : value(a), type(a.get_type()) {}
	  Symbol(Function f) : function(f), type(FUNCTION) {}
	  Symbol(Type t) { type = t; }
	  Symbol& operator = (Type t) {
	       type = t;
	  }
	  Symbol& operator = (Atom a) {
	       value = a;
	  }
     };
}
