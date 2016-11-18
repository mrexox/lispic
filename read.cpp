#include "read.h"
#include <locale>


namespace lispic {
     enum SYMBOL : char {
	  LP = '(', RP = ')',
	       LF = '\n', SPACE = ' ', TAB = '\t', //blank characters
	       DOT = '.',
	       QQ = '\"',
	       
	       };

     string to_upper (string str) {
	  std::locale loc;
	  string tmpstr;
	  stringstream ss;
  
	  for (string::size_type i = 0; i < str.length(); ++i) {
	       ss << std::toupper(str[i], loc);
	  }

	  ss >> tmpstr;
	  return tmpstr;
     }

     Reader::Reader() { }
     Reader::~Reader() { }
     void Reader::clear_blanks(string&, size_t& index) {
	  while ( i < str.length() && is_blank(str.at(i))  ) ++i;
	  str.erase(0, i);
     }
     bool Reader::is_blank(char ch) {
	  if (ch == SPACE || ch == LF || ch == TAB)
	       return true;
	  return false;
     }
     string read_atom(string& str) {
	  if (str.at(0) == QQ) {
	  } else {
	       return read_symbol(str);
	  }
     }
     string read_string(string& str) {
	  int i = 1;
	  while (str.at(i) != QQ) ++i; 
	  return str.substr(0, i) + QQ; // returns string "it's me!"
     }
     string read_symbol(string& str) {
	  int i = 1;
	  while (!is_blank(str.at(i)) && i < str.length()) ++i;
	  return str.substr(0, i);		 
     }
     string Reader::eat_s_expression(string& str, unsigned int parenthesis_count=0) {
	  size_t i = 0;
	  string s_exp;
	  try {
	       clear_blanks(str, i);

	       switch ( str.at(i) ) {
	       case LP:
		    parenthesis_count++;
		    s_exp += LP; 
		    str.erase(0, 1); // remove '(' symbol and keep going
		    s_exp += eat_s_expression(str, parenthesis_count);
		    break;
	       case RP:
		    parenthesis_count--;
		    s_exp += RP;
		    if (parenthesis_count == 0) {
			 break;
		    } else {
			 s_exp += SPACE;
			 str.erase(0, 1); // -//-
			 s_exp += eat_s_expression(str, parenthesis_count);
		    }
		    break;
	       default:
		    s_exp += read_atom(str);
		    clear_blanks(str, i);
		    if (parenthesis_count > 0) {
			 s_exp += SPACE;
			 s_exp += eat_s_expression(str, parenthesis_count);
		    }
		    break;
	       }
	  } 
	  catch ( std::out_of_range err) {
	       std::cerr << "End of file during parsing" << std::endl;
	  }
	  
	  return s_exp;
     }
     Reader& Reader::operator << (string str) {
	  do {
	       s_expressions.push(eat_s_expression(str));
	  } while (!str.empty());
	  
	  return *this;
     }
     Reader& Reader::operator >> (string str) {
	  
     }
     
}
