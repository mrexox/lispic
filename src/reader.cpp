#include "reader.h"
// TODO add readexpression to read from ( to matching )
namespace lispic
{
     namespace reader
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

	  std::vector<std::string> read_tokens(std::string& str)
	  {
	       std::vector<std::string> tokens;
	       std::string token;
	       str.erase(0, 1);
	       while (!(token = read_token(str)).empty())
	       {
		    tokens.push_back(token);
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
		    int i = 0;
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
}
