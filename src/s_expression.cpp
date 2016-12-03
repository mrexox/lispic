#include "s_expression.h"
using namespace lispic;

Symbol
funcall(List* list)
{
     Function& f = evalfunc( list->car() ); // evalfunc(Symbol&) -> Function*
     List& args = evallist( list->cdr() ); // evallist(List*) -> List*
     
     if (f->signature.length() != args->length()) {
	  throw signature_error();
     }
     
     Environment fenv;
     Environment senv;
     for (List::iterator p = args.begin(), Function::signature::iterator fp = f.signature.begin();
	  p != args.end(), fp != f.signature.end();
	  p++, fp++)
     {
	  switch ( (*p).get_type() )
	  {
	  case FUNCTION:
	       fenv[fp.name()] = (*p).function_value();
	       break;
	  case VARIABLE:
	       senv[fp.name()] = (*p).symbol_value();
	       break;
	  case ATOM:
	       senv[fb.name()] = (*p).atom_value();
	       break;
	  }
     }
     

     FENVS.push_back(fenv);
     Symbol result = f.call(ENVS);
     FENVS.pop_back();
     return result;
}
