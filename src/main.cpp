#include "stdafx.h"
#include "reader.h"
#include "evaluator.h"


using namespace lispic;

void execute(std::istream&, int);

int main(int argc, char** argv) {
     if (argc == 2 && strcmp(argv[1], "-i") == 0) {
	  execute(std::cin, FROM_CONSOLE);
     } else if (argc == 3 && strcmp(argv[1], "-e") == 0 ) {
	  // Third arg is supposed to be a string to evaluate
	  std::stringstream ss(argv[2], std::ios_base::in);
	  execute(ss, FROM_FILE);
     } else if (argc == 2) {
	  // Second arg is supposed to be a filename
	  std::ifstream fs(argv[1], std::ifstream::in);
	  execute(fs, FROM_FILE);
	  fs.close();
     } else {
	  std::cout << "Usage: lispic [-e '(...)'] | [-i] | filename.lisp" << std::endl;
     }
     return 0;
}


void execute(std::istream& in, int from)
{
     Reader& r = Reader::Get();
     Evaluator& e = Evaluator::Get();
     while ( !r.finished(in) )
     {
	  if (from == FROM_CONSOLE)
	       std::cout << "\n>> ";
	  try
	  {
	       Symbols read = r.read(in, from);
	       Symbol sym = e.eval(read);
	       std::cout << sym;
	       
	  } catch(const lispic_error& le) {
	       std::cerr << le.what();
	  }
     }
     std::cout << std::endl;
}


