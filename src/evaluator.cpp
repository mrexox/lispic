#include "stdafx.h"
#include "evaluator.h"
#include "reader.h"

namespace lispic {

//     extern static Environment *ENV;
     ENV = new Environment();

     number eval (string str )
     {     
	  reader::cut_blanks(str);	// needs reader!!!

	  string func_name;
	  numbers args;
	  list<string> tokens;
	  switch (str[0]) 
	  {
	  case LP:
	       func_name = reader::read_operation(str);
	       tokens = reader::read_args(str);
	       for(list<string>::const_iterator p = tokens.begin(); p != tokens.end(); ++p)
	       {
	       
		    args.push_back( eval(static_cast<string>(*p)) );
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

     number call(string func_name, numbers& args)
     {

	  return ENV->call(func_name, args);
     }

// HELP FUNCTIONS
// in Reader!!!
}
