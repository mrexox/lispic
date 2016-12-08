#include "stdafx.h"
#include "evaluator.h"


int main(int argc, char** argv)
{
     std::string s = "(+ 1 2 3 4 5)";
     lispic::number d = lispic::eval(s);
     std::cout << "The answere is: " << d << std::endl;
     return 0;
}
