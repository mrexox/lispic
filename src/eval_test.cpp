#include "stdafx.h"
#include "environment.h"
#include "evaluator.h"

namespace lispic {
     Environment ENV;
}

using namespace lispic;

int main(int argc, char** argv)
{
     ENV = Environment();
     std::string s;
     if (argc == 2) s = argv[1];
     else 
     {
	  s = "(+ 12 (- 123 31) (* 2 (- 1 4) 13))";
	  std::cout << s << std::endl;r
     }

     number d = eval(s);
     std::cout << "The answere is: " << d << std::endl;
     return 0;
}
