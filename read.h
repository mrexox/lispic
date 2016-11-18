#include "stdafx.h"
#include <ctype.h>
#include <sstream>
#include <stack>
#include <stdexcept>
using std::string;

namespace lispic {
     std::string to_upper (std::string);
     
     class Reader {
     private:
	  std::stack<std::string> s_expressions;
	  string eat_s_expression(string&, unsigned int);
	  bool is_blank(char);
	  void clear_blanks(string&, size_t&);
	  string read_atom(string&);
	  string read_string(string&);
	  string read_symbol(string&);
     public:
	  Reader();
	  ~Reader();
	  Reader& operator << (string);
	  Reader& operator >> (string);
	  
     };
     
	  }
