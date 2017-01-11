#pragma once
#include <string>

namespace lispic
{
     typedef double Number;
    
     enum SUGAR : char {
	  LP = '(',
	       RP = ')',
	       QQ = '\"',
	       
	       LINEFEED = '\n',
	       TAB = '\t',
	       SPACE = ' ',
	       COMMENT = ';',
	       };

     class lispic_error : public std::logic_error
     {
     public:
	  lispic_error(const std::string msg) : logic_error(msg) { }

     };	
}
