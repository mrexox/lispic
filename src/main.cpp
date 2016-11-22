#include "stdafx.h"
#include "read.h"

using namespace lispic;

int main() {
     Reader reader;
     string tmp;
     int n = 10;
     while (true) {
	  std::cout << "> ";
	  std::cin >> reader;
	  while(reader.has_some())
	       std::cout << reader << std::endl;
     }
     
     return 0;
}
