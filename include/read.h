#include "stdafx.h"
#include <ctype.h>
#include <sstream>
#include <queue>
#include <stdexcept>
using std::string;

namespace lispic {
     string to_upper (string);


     class Reader {
     private:
	  std::queue<string> s_expressions;
	  string eat_s_expression(string&, unsigned int);
	  bool is_blank(char);
	  void clear_blanks(string&, size_t&);
	  string read_atom(string&);
	  string read_string(string&);
	  string read_symbol(string&);
	  friend std::ostream& operator << (std::ostream& , Reader& );
	  friend std::istream& operator >> (std::istream&, Reader&);
     public:
	  Reader& operator << (string);
	  Reader& operator >> (string);
	  bool has_some();
     };
     
	  }
