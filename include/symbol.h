#pragma once
#include "atom.h"
#include "function.h"

namespace lispic {
     class Symbol {
	  symbol_type type;
	  string name;
	  Atom* atom;
	  Function* function;
     public:
	  Symbol(Atom* a) : value(a), type(a.get_type()) {}
	  Symbol(Function* f) : function(f), type(FUNCTION) {}
	  Symbol(List* l) : lsit(l), type(LIST) {}
	  ~Symbol();		//  delete if atom

	  symbol_type get_type() { return type; }
	  Atom* atom_value() { return atom; }
	  Atom* symbol_value() { return SENVS.find(name); }
	  Function* function_value() { return function; }
     };
}
