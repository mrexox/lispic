#pragma once
#include "stdafx.h"
#include "function.h"
#include "symbol.h"



namespace lispic
{
     class UserFunction : public Function
     {
	  /*
	    Local Environment fills the signature symbols
	    if any symbol is defined in function it is added to it
	  */
	  class LocalEnvironment : public Environment<std::string, Symbol::Value>
	  {
	       Symbol::Value set(std::string&, Symbol::Value&);
	  };

     public:
     };
}
