#pragma once
#include "stdafx.h"
#include "environment.h"

namespace lispic
{
     extern Environment ENV;
     

     number eval (std::string);
     number call(std::string, numbers&);

     // HELP FUNCTIONS
     // in reader!!! namespace
     bool is_blank(const char ch);

     // STD::EXCEPTIONS
     class empty_input : public std::exception
     {
	  const char * message;
     public:
	  empty_input(const char* msg) { message = msg; }
	  virtual const char* what() const throw()
	       {
		    return message;
	       }
     };

     class syntax_error : public std::exception
     {
	  const char * message;
     public:
	  syntax_error(const char* msg) { message = msg; }
	  virtual const char* what() const throw()
	       {
		    return message;
	       }
     };
}
