#include "reader.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;
using namespace lispic;

int main(int argc, char** argv)
{
     if (argc != 2) return 1;
     string s = argv[1];
     cout << "Operation: " << reader::read_operation(s) << endl;
     list<string> l = reader::read_args(s);
     cout << "Args: ";
     for( list<string>::iterator p = l.begin(); p != l.end(); ++p)
     {
	  cout << '\'' << *p << "' ";
	  
     }
     cout << endl;
     return 0;
}
