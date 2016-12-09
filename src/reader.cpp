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
	  std::string read_operation(std::string& str)
	  {
	       if (str[0] != LP) throw input_error("Expected '('");
	       str.erase(0, 1);

	       return read(str);
	  }
	  std::list<std::string> read_args(std::string& str)
	  {
	       std::list<std::string> args;
	       std::string check;
	       while(str.length()) if( ( check = read(str) ) != "" ) args.push_back(check);
	       return args;
	  }

	  std::string read(std::string& str)
	  {
	       int parenths = 0;
	       std::string accumulator = "";
	       bool in_list = false;
	       bool reading_atom = false;
	       cut_blanks(str);
	       for (std::string::iterator p = str.begin(); p != str.end(); ++p)
	       {
		    if ( (is_blank(*p)  && !in_list)
			 || (parenths <= 0 && in_list)) {
			 str.erase(str.begin(), p);
			 return accumulator;
		    }
		    switch(*p) {
		    case LP: 
			 if (reading_atom) {
			      str.erase(str.begin(), p);
			      return accumulator;
			 }
			 parenths++;
			 in_list = true;
			 accumulator += LP;
			 break;
		    case RP:
			 parenths--;
			 if (in_list) accumulator += RP;
			 break;
		    default:
			 accumulator += *p;
			 reading_atom = true;
			 break;
		    }
	       }
	       str.erase(str.begin(), str.end());
	       return accumulator;
	  }
     }
}
