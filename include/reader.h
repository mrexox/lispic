#pragma once
#include "stdafx.h"
#include "types.h"
#include "tokens.h"

namespace lispic 
{
     class Reader
     {
     public:
	  static Reader& Get()
	       {
		    static Reader r;
		    return r;
	       }
	  Tokens read_tokens(std::string& str);
	  bool finished();
     private:
	  Reader() {}
	  ~Reader() {}

	  Reader(const Reader&);
	  Reader& operator= (const Reader&);
	  
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
     };
}
