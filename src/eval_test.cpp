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
     if (argc != 2) return 1;
     std::string s = argv[1];
     number d = eval(s);
     std::cout << "The answere is: " << d << std::endl;
     return 0;
}
