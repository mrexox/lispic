#pragma once

namespace lispic
{
     typedef double number;
     typedef std::list<number> numbers;
     typedef number (*num_func)(numbers);

     
     enum SUGAR : char {
	  LP = '(',
	       RP = ')',
	       
	       };

}
