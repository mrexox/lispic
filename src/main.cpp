#include "stdafx.h"
#include "read.h"
#include "s_expression.h"
using namespace lispic;

void loop(std::istream&);

S_expression eval(S_expression&);
S_expression eval(List&);
S_expression eval(Function, List);
S_expression eval(Symbol&);

int main(int argc, char ** argv) {
     // Usage: lispic filename.lisp 
     // or:    lispic
     if (argc == 2) {
	  std::filebuf fb;
	  if (fb.open( argv[1], std::ios::in )) {
	       std::istream in(&fb);
	       loop(in);
	       fb.close();
	  } else {
	       std::cerr << "Couldn't open file '" << argv[1] << "' for reading" << endl;
	  }	  
     } else {
	  loop(std::cin);
     }
     std::cout << "Exiting\n";
     return 0;
}

void loop(std::istream& in) 
{
     Reader reader;
     while (in.get()) {
	  in.unget();
	  std::cout << "> ";
	  in >> reader;		// when input is '\n' doesn't return
	  while(reader.has_some()) {
	       // parse s expression
	       // eval s expression
	       // print s expression
	       // print( eval( read(in) ) );
	       std::cout << reader << std::endl;    
	  }
     }
}

bS_expression eval(S_expression& s_expr)
{
     switch( s_expr.get_type() ) {

     }
}
