#include "reader.h"
// TODO add readexpression to read from ( to matching )
namespace lispic
{
     bool is_blank(const char ch) 
     {
	  switch (ch) {
	  case ' ':  case '\n':  case '\t':
	       return true;
	       break;
	  default:
	       return false;
	       break;
	  }
     }

     void cut_blanks(std::string& str)
     {
	  int blanks = 0;
	  while (is_blank(str[blanks])) blanks++;
	  str.erase(0, blanks);
     }

     Tokens Reader::read_tokens(std::string& str)
     {
	  Tokens tokens;
	  std::string token;
	  str.erase(0, 1);
	  while (!(token = read_token(str)).empty())
	  {
	       tokens.push(token);
	  }
	  return tokens;
     }
     std::string read_token(std::string& str)
     {
	  cut_blanks(str);
	  if (str.empty()) return str;
	  if (str[0] == LP) {
	       return read_list(str);
	  } 
	  else {
	       std::string acc = "";
	       unsigned int i = 0;
	       while (is_token(str[i]) && str[i] != LP && i < str.length()) i++;
	       acc = str.substr(0, i);
	       str.erase(0, i);
	       return acc;
	  }
     }

     std::string read_list(std::string& str)
     {	       
	  // first arg must be left parenthesis
	  if (str[0] != LP) throw input_error("Expected '('");
	  // can be optimized
	  int parenthes = 0;
	  int i = 0;
	  do {
	       if (str[i] == LP) parenthes++;
	       else if (str[i] == RP) parenthes--;
	       i++;
	  } while(parenthes && !str.empty());
	  if (str.empty())
	  {
	       throw input_error("Expected ')'");
	  }
	  std::string acc = str.substr(0, i);
	  str.erase(0, i);
	  return acc;
     }

     bool is_token(const char ch) {
	  if (is_blank(ch) || ch == LP || ch == RP) {
	       return false;
	  }
	  return true;
     }

}
