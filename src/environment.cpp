#include "environment.h"

namespace lispic {
     number Environment::plus(numbers args)
     {
	  number res = 0;
	  for(numbers::iterator p = args.begin(); p != args.end(); ++p) {
	       res += *p;
	  }
	  return res;
     }

     number Environment::minus(numbers args)
     {     
	  number res = 0;
	  for(numbers::iterator p = args.begin(); p != args.end(); ++p) {
	       res -= *p;
	  }
	  return res;
     }

     number Environment::product(numbers args)
     {
	  number res = 1;
	  for(numbers::iterator p = args.begin(); p != args.end(); ++p) {
	       res *= *p;
	  }
	  return res;
     }

     number Environment::divide(numbers args)
     {
	  numbers::iterator p = args.begin();
	  number res = *p++;
	  while (p != args.end())
	  {
	       res /= *p++;
	  }
	  return res;
     }

     number Environment::power(numbers args) // a ^ b
     {
	  if (args.size() != 2) 
	       throw bad_args("POWER: wrong number of arguments!");
	  numbers::iterator num = args.begin();
	  return pow(*num, *(++num));
     }

     number Environment::call(string name, numbers args) 
     {
	  if (name == "+") {
	       return plus(args);
	  } else if (name == "-") {
	       return minus(args); 
	  } else if (name == "*") {
	       return product(args);
	  } else if (name == "/") {
	       return divide(args); 
	  } else if (name == "^") {
	       return power(args);
	  } else {
	       char * errstr = "Unknown function: ";
	       strcat(errstr, name.c_str());
	       throw unknown_function(errstr);
	  }
     }
}
