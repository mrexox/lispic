#pragma once
#include "stdafx.h"
#include "symbol.h"


namespace lispic
{
     class Evaluator
     {
	  
     public:
	  static Evaluator& Get()
	  {
	       static Evaluator e;
	       return e;
	  }
	  Symbol eval(Symbols);

	  class eval_error : public std::exception
	  {
	       const char * message;
	  public:
	       eval_error(const char* msg) { message = msg; }
	       virtual const char* what() const throw()
		    {
			 return message;
		    }
	  };
     private:
	  void eval_list(Symbols&);
	  bool like_num(Symbol&);
	  bool like_str(Symbol&);
	  void eval_symbol(Symbol&);
	  void send_to_env(Symbol&);
     };
}
