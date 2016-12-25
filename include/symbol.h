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
	  Symbol(std::string name) : name(name) {}
	  std::string name() { return _name; }
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
	  Type type() { return _type; }
	  // suppose to fill symbols with values
	  number& number();
	  std::string& string();
	  Function& function();
	  Symbols& list();

	  friend std::ostream operator << (const Symbol&);
     };
     std::ostream operator << (const Symbol&);
     typedef std::vector<Symbol> Symbols;     
}
