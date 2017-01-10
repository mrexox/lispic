#pragma once
#include "stdafx.h"
#include "function.h"


namespace lispic
{
     class Symbol;
     typedef std::vector<Symbol> Symbols;

     enum Type
     {
	  NUMBER, STRING,
	  FUNCTION, NIL,
	  LIST, ATOM,
     };

     class Symbol 
     {
     public:
	  class Value
	  {
	       Number _number;
	       std::string _string;
	       Function* _pfunction = 0;
	       Symbols _list;
	       Type _type = ATOM;
	  public:
	       Value()
		    {
			 _type = NIL;
			 _number = 0;
			 _string = "";
		    }
	       Value(Symbols list) : _list(list) { _type = LIST; }
	       Value(std::string str) : _string(str) { _type = STRING; }
	       Value(Number num) : _number(num) { _type = NUMBER; }
	       Value(Function* p_function) : _pfunction(p_function) { _type = FUNCTION; }
	       // ~Value()
	       // 	    {
	       // 		 if ( _pfunction )
	       // 		      delete _pfunction;
	       // 	    }
	       
	       Type type() const { return _type; }
	       Function* pfunction()  { return _pfunction; }
	       std::string string() const { return _string; }
	       Number number() const { return _number; }
	       Symbols& list()  { return _list; }
	       
	       friend std::ostream& operator << (std::ostream&, Symbol::Value&);
	       
//	       operator Number () { return _number; }
//	       operator std::string () { return _string; }
	  };
     private:
	  std::string _name;
	  Value _value;
     public:
	  Symbol() : _value() { _name = "nil"; }
	  Symbol(std::string name) : _name(name) {}
	  Symbol(Symbols symbols) : _value(symbols) {}
	  Symbol(std::string name, Value value) : _name(name), _value(value) {}
	  
	  std::string name() const { return _name; }
	  Type type() const { return _value.type(); }
	  
	  Value value() const  { return _value; }
	  void set(Value v) { _value = v; }
	  
	  Symbols list() {return _value.list();}
	  Symbol& fill(Value& v) { _value = v; return *this; }

	  friend std::ostream& operator << (std::ostream&, const Symbol&);
	  friend std::ostream& operator << (std::ostream&, Symbols&);
	  
	  // Symbol& operator = (const Symbol& symbol)
	  //      {
	  // 	    _name = symbol._name;
	  // 	    _value = symbol._value;
	  // 	    return *this;
	  //      }
     };
     std::ostream& operator << (std::ostream& out, const Symbol& s);
     std::ostream& operator << (std::ostream&, Symbols&);
     std::ostream& operator << (std::ostream& out, const Symbol::Value& value);
}
