#pragma once
#include <string>

namespace lispic
{
     typedef double Number;
     typedef std::vector<Number> Numbers;
     typedef Number (*num_func)(Numbers);
     /*    Number ston(std::string str) {
	  return std::stod(str);
	  }*/
     
     enum SUGAR : char {
	  LP = '(',
	       RP = ')',
	       QQ = '\"',
	       
	       LINEFEED = '\n',
	       TAB = '\t',
	       SPACE = ' ',
	       COMMENT = ';',
	       };
     class lispic_error : public std::exception
     {
	  const char * message;
     public:
	  lispic_error(const std::string msg) { message = msg.c_str(); }
	  virtual const char* what() const throw()
	       {
		    return message;
	       }
     };	
}
