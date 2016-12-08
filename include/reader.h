#pragma once
#include "stdafx.h"
#include "types.h"
using std::string;

namespace lispic {
     namespace reader
     {
	  void cut_blanks(string&);	// needs reader!!!
	  string read_operation(string&);
	  list<string> read_args(string&);
	  string read(string&); // must return double
	  bool is_blank(const char ch) ;

	  class input_error : public exception
	  {
	       const char * message;
	  public:
	       input_error(const char* msg) { message = msg; }
	       virtual const char* what() const throw()
		    {
			 return message;
		    }
	  };
     }     
}
