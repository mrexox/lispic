#include "evaluator.h"
#include "reader.h"

namespace lispic {
     number eval (std::string str )
     {     
	  reader::cut_blanks(str);	// needs reader!!!

	  std::string func_name;
	  numbers args;
	  std::vector<std::string> tokens;
	  switch (str[0]) 
	  {
	  case LP:
	       tokens = reader::read_tokens(str); // implement using read_token and read_list;
	       func_name = tokens.at(0);
	       tokens.erase(tokens.begin());
	       for(std::vector<std::string>::const_iterator p = tokens.begin(); p != tokens.end(); ++p)
	       {
	       
		    args.push_back( eval(static_cast<std::string>(*p)) );
	       }
	       return call(func_name, args);
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
