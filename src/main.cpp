#include "stdafx.h"
#include "reader.h"
#include "evaluator.h"
using namespace lispic;

void interactive(void);
void execute(std::istream);
int main(int argc, char** argv) {
     if (argc == 2) {
	  // Second arg is supposed to be a filename
	  std::ifstream fs(argv[1], std::ifstream::in);
	  execute(fs);
	  in.close();
     } else if (argc == 3 && strcmp(argv[1], '-e')) {
	  // Third arg is supposed to be a string to evaluate
	  std::stringstream ss(argv[2], std::ios_base::in);
	  execute(ss);
     } else {
	  interactive();
     }
     return 0;
}


void execute(std::istream in)
{
     Reader r = Reader::Get();
     Evaluator e = Evaluator::Get();
     try {
	  while ( !r.finished() )
	  {
	       Symbols syms = r.read(in);
	       Symbol sym = e.eval(syms);
	       std::cout << sym;
	  }
     } catch (std::exception ex) {
	       std::err << "Exception -> " << ex.what() << std::endl;
     }
}

void interactive(void)
{
     execute(std::cin);
}

