#pragma once
#include "stdafx.h"
#include "value.h"

namespace lispic
{

     class Symbol 
     {
	  std::string _name;
	  Value _value;
     public:
	  Symbol() : _value() {}
	  Symbol(std::string name) : _name(name) {}
	  Symbol(Symbols symbols) : _value(symbols) {}

	  std::string name() const { return _name; }
	  Type type() const { return _value.type(); }
	  Value value() const { return _value; }
	  Symbols list() {return _value.list();}

	  friend std::ostream& operator << (std::ostream&, const Symbol&);
	  
	  Symbol& operator = (const Value& value)
	       {
		    _value = value;
		    return *this;
	       }
	  Symbol& operator = (const Symbol& symbol)
	       {
		    _value = symbol.value();
		    return *this;
	       }
     };
     std::ostream& operator << (std::ostream&, const Symbol&);

}
