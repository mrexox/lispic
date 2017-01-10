#include "user_func.h"

namespace lispic
{
     Symbol UserFunction::call(Symbols& args)
     {
	  
	  Repository::VariablesEnvironment venv;
	  for(Symbols::iterator sig = signature.begin(),
		    arg = args.begin();
	      sig != signature.end() &&
		   arg != args.end();
	      ++sig, ++arg)
	  {
	       venv[sig->name()] = arg->value();
	  }
	  Repository::Get().variables.push_back(venv);
	  Symbol res = Evaluator::Get().eval(body);
	  Repository::Get().variables.pop_back();
	  return res;
     }
}
