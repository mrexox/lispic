#include "evaluator.h"
#include "reader.h"

namespace lispic {
     number eval (std::string str )
     {     
	  reader::cut_blanks(str);	// needs reader!!!

	  std::string func_name;
	  numbers args;
	  std::list<std::string> tokens;
	  switch (str[0]) 
	  {
	  case LP:
	       func_name = reader::read_operation(str);
	       tokens = reader::read_args(str);
	       for(std::list<std::string>::const_iterator p = tokens.begin(); p != tokens.end(); ++p)
	       {
	       
		    args.push_back( eval(static_cast<std::string>(*p)) );
	       }
	       return call(func_name, args);
	       break;
	  case RP:
	       throw syntax_error("Unexpected ')'");
	       break;
	  default:
	       return std::stod( reader::read(str) ); // must return double
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
