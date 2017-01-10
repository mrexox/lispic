#pragma once
#include "stdafx.h"
#include "symbol.h"
#include "function.h"
#include "evaluator.h"
#include "repository.h"

namespace lispic
{
     class UserFunction : public Function
     {
	  /*
	    Local Environment fills the signature symbols
	    if any symbol is defined in function it is added to it
	  */
	  // class LocalEnvironment : public Environment<std::string, Symbol::Value>
	  // {
	  //      Symbol::Value set(std::string&, Symbol::Value&);
	  // };
	  typedef Symbol (*user_function)(Symbols&);
	  user_function function;
	  Symbols signature;
	  Symbols body;
	  
     public:
	  UserFunction(Symbols& signature, Symbols& body)
	       : signature(signature), body(body) {}
	       
	  Symbol call(Symbols&);
     };

     
     
}
