/*
  Value contains all types and represents them
  
 */

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
	  Value(Symbols list) : _list(list) { _type = LIST; }
	  ~Value() { if (_pfunction) delete _pfunction; }
	  Value(std::string str) : _string(str) { _type = STRING; }
	  Value(Number num) : _number(num) { _type = NUMBER; }
	  
	  Type type() const { return _type; }
	  Function* pfunction()  { return _pfunction; }
	  std::string string()  { return _string; }
	  Number number()  { return _number; }
	  Symbols& list()  { return _list; }

	  operator Number () { return _number; }
	  operator std::string () { return _string; }
	  
	  Value& operator = (const Value& value)
	       {
		    _type = value._type;
		    switch ( value._type )
		    {
		    case NUMBER:
			 _number = value._number;
			 break;
		    case STRING:
			 _string = value._string;
			 break;
		    case FUNCTION:
			 _pfunction = value._pfunction;
			 break;
		    case LIST:
			 _list = value._list;
			 break;
		    case NIL:			 
			 break;
		    default:			 
			 break;
		    }
			 return *this;
	       }

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
	  
	  Value& operator = (Function* const pfunction)
	       {
		    _pfunction = pfunction;
		    _type = FUNCTION;
		    return *this;
	       }
//	  friend std::ostream& operator << (std::ostream& out, const Value& v);
     };
     /*   
	  std::ostream& operator << (std::ostream& out, const Value& v)
	  {
	  switch ( v.type() )
	  {
	  case NUMBER:
	  out << v.number();
	  break;
	  case STRING:
	  out << v.string();
	  break;
	  case FUNCTION:
	  out << "#<Function>";
	  break;
	  case LIST:
	  out << v.list();
	  break;
	  case NIL:
	  out << "nil";
	  break;
	  default:
	  out << "!Error, not initialized symbol!";
	  break;
	  }
	  return out;
	  }
     */
}
