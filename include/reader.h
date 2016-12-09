#pragma once
#include "stdafx.h"
#include "types.h"

namespace lispic 
{
     namespace reader
     {
	  void cut_blanks(std::string&);	// needs reader!!!
	  std::string read_operation(std::string&);
	  std::list<std::string> read_args(std::string&);
	  std::string read(std::string&); // must return double
	  bool is_blank(const char ch);

	  class input_error : public std::exception
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
