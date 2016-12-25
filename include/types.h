#pragma once

namespace lispic
{
     typedef double number;
     typedef std::list<number> numbers;
     typedef number (*num_func)(numbers);
     number ston(std::string str) {
	  return std::stod(str);
     }
     
     enum SUGAR : char {
	  LP = '(',
	       RP = ')',
	       
	       };

}
