#pragma once
#include "stdafx.h"
using namespace std;

namespace lispic
{
     class Environment 
     {
	  static number plus(numbers);
	  static number minus(numbers);
	  static number product(numbers);
	  static number divide(numbers);
	  static number power(numbers); // a ^ b
     
	  class bad_args : public exception
	  {
	       const char * message;
	  public:
	       bad_args(const char* msg) { message = msg; }
	       virtual const char* what() const throw()
		    {
			 return message;
		    }
	  };

	  class unknown_function : public exception
	  {
	       const char * message;
	  public:
	       unknown_function(const char* msg) { message = msg; }
	       virtual const char* what() const throw()
		    {
			 return message;
		    }

	  };
     public:
	  static number call(string, numbers);
     };
}
