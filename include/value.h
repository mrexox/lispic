#pragma once
#include "stdafx.h"
#include "function.h"

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

     class Symbol;
     typedef std::vector<Symbol> Symbols;
     
     class Value
     {
	  Number _number;
	  std::string _string;
	  Function* _pfunction = 0;
	  Symbols _list;
	  Type _type = ATOM;
	  void init_null()
	       {
		    _type = NIL;
		    _number = 0;
		    _string = "";
	       }
     public:
	  Value() { init_null(); _type = NIL; }
	  Value(Number number) : _number(number) {_type = NUMBER;}
	  Value(std::string string) : _string(string) {_type = STRING;}
	  Value(Symbols list) : _list(list) {_type = LIST; }
	  Value(Function* pfunction)  { _pfunction = pfunction; _type = FUNCTION;}
	  ~Value() { if (_pfunction) delete _pfunction; }

	  Type type() const { return _type; }
	  Function* pfunction() const { return _pfunction; }
	  std::string string() const { return _string; }
	  Number number() const { return _number; }
	  Symbols list() { return _list; }

	  operator Number () { return _number; }
	  operator std::string () { return _string; }
	  
	  
	  Value& operator = (const Number& number)
	       {
		    _number = number;
		    _type = NUMBER;
		    return *this;
	       }
	  
	  Value& operator = (const std::string& string)
	       {
		    _string = string;
		    _type = STRING;
		    return *this;
	       }
	  
	  Value& operator = (const Symbols& list)
	       {
		    _list = list;
		    _type = LIST;
		    return *this;
	       }
	  
	  Value& operator = (const Function* pfunction)
	       {
		    pfunction = pfunction;
		    _type = FUNCTION;
		    return *this;
	       }
	  
     };
}
