#include "evaluator.h"
#include "reader.h"

namespace lispic {
     number eval (std::string str )
     {
	  Reader r = Reader::Get();
	  	  
	  std::string func_name;
	  numbers arguments;
	  Tokens tokens;
	  Args args;
	  switch (str[0]) 
	  {
	  case LP:
	       tokens = r.read_tokens(str); // implement using read_token and read_list;
	       func_name = tokens.function();
	       args = tokens.args();
	       for(Args::const_iterator p = args.begin(); p != args.end(); ++p)
	       {
	       
		    arguments.push_back( eval(static_cast<std::string>(*p)) );
	       }
	       return call(func_name, arguments);
	       break;
	  case RP:
	       throw syntax_error("Unexpected ')'");
	       break;
	  default:
	       return std::stod( reader::read_token(str) ); // must return double
	       break;
	  }
	  // can't reach here!
	  return 0;
     }

     number call(std::string func_name, numbers& args)
     {
	  return ENV.call(func_name, args);
     }

// HELP FUNCTIONS
// in Reader!!!
}
