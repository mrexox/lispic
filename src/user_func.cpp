#include "user_func.h"

namespace lispic
{
     Symbol UserFunction::call(Symbols& args)
     {
	  if (args.size() != signature.size())
	       throw call_error("Wrong number of arguments, given: "
				+ std::to_string(args.size())
				+ ", needs: " + std::to_string(signature.size()));
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
