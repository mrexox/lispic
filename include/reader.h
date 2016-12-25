#pragma once
#include "stdafx.h"
#include "symbol.h"


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
	  bool finished(std::istream in);
	  Symbols read(std::istream in);
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
