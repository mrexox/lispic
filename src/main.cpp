#include "reader.h"
#include "builtins.h"
#include "environment.h"
using namespace lispic;

Environment ENV;

int main(int argc, char** argv) {
     // Usage: lispic filename.lisp 
     // or:    lispic
     ENV = Environment();
     std::cout << "Bue!" << std::endl;
     return 0;
}

