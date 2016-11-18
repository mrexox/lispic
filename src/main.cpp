#include "stdafx.h"
#include "read.h"

using namespace lispic;

int main() {
     Reader reader;
     string str = "(+   2(- 12 7 )1 2 3   ) hi \"this is the end\" 23";
     reader << str;
     while (reader.has_some()) {
	  std::cout << reader << std::endl;
     }
     
     return 0;
}
