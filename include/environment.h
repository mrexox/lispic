#pragma once
#include "stdafx.h"

namespace lispic
{
     class Environment 
     {
	  number plus(numbers);
	  number minus(numbers);
	  number product(numbers);
	  number divide(numbers);
	  number power(numbers); // a ^ b
     public:
	  number call(std::string, numbers&);
     };

// STD::EXCEPTIONS
     class bad_args : public std::exception
     {
	  const char * message;
     public:
	  bad_args(const char* msg) { message = msg; }
	  virtual const char* what() const throw()
	       {
		    return message;
	       }
     };

     class unknown_function : public std::exception
     {
	  const char * message;
     public:
	  unknown_function(const char* msg) { message = msg; }
	  virtual const char* what() const throw()
	       {
		    return message;
	       }

     };
}