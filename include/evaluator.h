#pragma once
#include "stdafx.h"
#include "environment.h"

namespace lispic
{
     static Environment *ENV;

     number eval (string str );
     number call(string func_name, numbers& args);

     // HELP FUNCTIONS
     // in reader!!! namespace
     bool is_blank(const char ch);

     // EXCEPTIONS
     class empty_input : public exception
     {
	  const char * message;
     public:
	  empty_input(const char* msg) { message = msg; }
	  virtual const char* what() const throw()
	       {
		    return message;
	       }
     };

     class syntax_error : public exception
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
