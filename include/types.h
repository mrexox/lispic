#pragma once

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

}
