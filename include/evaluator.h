/*
  Evaluator asks Repository to get values from symbols' names
  Then it puts these values if they are atomic or calls function if a list is found
  
  If the funcall is special, values are not evaluated
*/

#pragma once
#include "stdafx.h"
#include "symbol.h"
#include "repository.h"
#include "function.h"

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

	  Symbol eval(Symbols&);

     private:
	  Evaluator() {}
	  Evaluator(Evaluator&) {}

	  bool like_num(Symbol&);
	  bool like_str(Symbol&);
	  bool is_special(std::string);

	  Symbol do_this_list(Symbols&);
	  Symbols eval_list(Symbols);
	  Symbol eval_symbol(Symbol&);
	  Symbol eval_to_number(Symbol&);
	  Symbol eval_to_string(Symbol&);
	  Symbol get_from_env(std::string);
	  Symbol make_function_call(Symbols&);
	  Symbol make_special_call(Symbols&);

	  friend Symbol set(Symbols&);
	  friend Symbol def(Symbols&);
     };

     class eval_error : public lispic_error {
     public:
	  eval_error(const std::string msg) : lispic_error(msg) {}
     };
}
