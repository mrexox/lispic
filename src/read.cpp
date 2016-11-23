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
	  std::stringstream ss;
  
	  for (string::size_type i = 0; i < str.length(); ++i) {
	       ss << std::toupper(str[i], loc);
	  }

	  ss >> tmpstr;
	  return tmpstr;
     }

     Reader::Reader() { }
     Reader::~Reader() { }
     void Reader::clear_blanks(string& str, size_t& index) {
	  unsigned int i = 0;
	  while ( i < str.length() && is_blank(str.at(i))  ) ++i;
	  str.erase(0, i);
     }
     bool Reader::is_blank(char ch) {
	  if (ch == SPACE || ch == LF || ch == TAB)
	       return true;
	  return false;
     }
     string Reader::read_atom(string& str) {
	  if (str.at(0) == QQ) {
	       return read_string(str);
	  } else {
	       return read_symbol(str);
	  }
     }
     string Reader::read_string(string& str) {
	  unsigned int i = 1;
	  while (str.at(i) != QQ) ++i; 
	  string sub = str.substr(0, i++) + '\"'; // returns string "it's me!"
	  str.erase(0, i);
	  return sub;
     }
     string Reader::read_symbol(string& str) {
	  unsigned int i = 0;
	  while ( i < str.length()
		  && !is_blank(str.at(i)) 
		  && str.at(i) != RP 
		  && str.at(i) != LP) ++i;
	  string sub = str.substr(0, i);
	  str.erase(0, i);
	  return sub;
     }
     string Reader::eat_s_expression(string& str, unsigned int parenthesis_count=0) {
	  size_t i = 0;
	  string s_exp;
	  try {
	       clear_blanks(str, i);

	       switch ( str.at(0) ) {
	       case LP:
		    parenthesis_count++;
		    s_exp += LP; 
		    str.erase(0, 1); // remove '(' symbol and keep going
		    s_exp += eat_s_expression(str, parenthesis_count);
		    break;
	       case RP:
		    parenthesis_count--;
		    s_exp += RP;
		    str.erase(0, 1); // -//-
		    if (parenthesis_count == 0) {
			 break;
		    } else {
			 s_exp += eat_s_expression(str, parenthesis_count);
		    }
		    break;
	       default:
		    if (parenthesis_count > 0)	
			 s_exp += SPACE;
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

     std::istream& operator >> (std::istream& in, Reader& reader) {
	  char ch;
	  int open_parenthesis = 0;
	  string summary;
	  in.get(ch);
	  while (open_parenthesis > 0 || ch != '\n') {
	       switch (ch) {
	       case LP:
		    open_parenthesis++;
		    break;
	       case RP:
		    open_parenthesis--;
		    break;
	       default:
		    break;
	       }
	       summary += ch;
	       in.get(ch);
	  } 
	  reader << summary;
	  return in;
     }
     
     std::ostream& operator << (std::ostream& out, Reader& reader) {
	  out << reader.s_expressions.front();
	  reader.s_expressions.pop();
	  return out;
     }

     bool Reader::has_some() {
	  return !s_expressions.empty();
     }
}
