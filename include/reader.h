/*
  Reads the input
  when from console: line by line
  when from file: wraps all lines in list and returns it
 */
#pragma once
#include "stdafx.h"
#include "symbol.h"

#define FROM_FILE 0
#define FROM_CONSOLE 1

namespace lispic 
{
     class Reader
     {
	  bool reading_finished;
     public:
	  static Reader& Get()
	  {
	       static Reader r;
	       return r;
	  }
	  bool finished(std::istream&);
	  Symbols read(std::istream&, int);
	  
     private:
	  Reader() {}
	  ~Reader() {}

	  Reader(const Reader&);
	  Reader& operator= (const Reader&);

	  Symbol read_string(std::istream& in);
	  Symbol read_symbol(std::istream& in);
	  Symbol read_list(std::istream& in);
	  Symbol read_atom(std::istream& in);
	  bool is_blank(const char& ch) const;
	  bool is_space(const char& ch) const;

	  
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

	  class read_error : public std::exception
	  {
	       const char * message;
	  public:
	       read_error(const char* msg) { message = msg; }
	       virtual const char* what() const throw()
	       {
		    return message;
	       }
	  };
     };
}
