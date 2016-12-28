#pragma once
#include "stdafx.h"

namespace lispic
{
     enum Type {
	  NUMBER,
	  STRING,
	  FUNCTION,
	  ATOM,
	  LIST,
	  NIL,
     };
     class Symbol 
     {
	  std::string _name;
	  number _number;
	  std::string _string;
	  Function _function;
	  Symbols _list;
	  Type _type;
     public:
	  Symbol() { _type = NIL; }
	  Symbol(std::string name) : name(name) {}
	  std::string name() { return _name; }
	  Symbol& init(Symbol& sym)
	  {
	       switch (sym.type())
	       {
	       case NUMBER: _number = sym.number(); break;
	       case STRING: _string = sym.string(); break;
	       case FUNCTION: _function = sym.function(); break;
	       case LIST: _list = sym.list(); break;
	       default:
		    _type = NIL;
		    break;
	       }
	       return *this;
	  }
	  
	  Symbol& init(number an)
	  {
	       n = an;
	       _type = NUMBER;
	       return *this;
	  }
	  
	  Symbol& init(std::string as)
	  {
	       s = as;
	       _type = STRING;
	       return *this;
	  }
	  
	  Symbol& init(Function af)
	  {
	       f = af;
	       _type = FUNCTION;
	       return *this;
	  }
	  
	  Symbol& init(Symbols ss)
	  {
	       syms = ss;
	       _type = LIST;
	       return *this;
	  }

	  Symbol& init()
	       {
		    _type = NIL;
		    _number = 0;
		    _string = "";
		    return *this;
	       }
	  Type type() { return _type; }
	  // suppose to fill symbols with values
	  number number() const;
	  std::string string() const;
	  Function function() const;
	  Symbols list() const;

	  friend std::ostream operator << (const Symbol&);
     };
     std::ostream operator << (const Symbol&);
     typedef std::vector<Symbol> Symbols;     
}
