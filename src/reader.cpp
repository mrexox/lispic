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

	  void cut_blanks(string& str)
	  {
	       int blanks = 0;
	       while (is_blank(str[blanks])) blanks++;
	       str.erase(0, blanks);
	  }
	  string read_operation(string& str)
	  {
	       if (str[0] != LP) throw input_error("Expected '('");
	       str.erase(0, 1);

	       return read(str);
	  }
	  list<string> read_args(string& str)
	  {
	       list<string> args;
	       while(str.length()) args.push_back(read(str));
	       return args;
	  }

	  string read(string& str)
	  {
	       int parenths = 0;
	       string accumulator = "";
	       bool in_list = false;
	       cut_blanks(str);
	       for (string::iterator p = str.begin(); p != str.end(); ++p)
	       {
		    if ( (is_blank(*p) && !in_list)
			 || (parenths <= 0 && in_list)) {
			 str.erase(str.begin(), p);
			 return accumulator;
		    }
		    switch(*p) {
		    case LP: 
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
			 break;
		    }
	       }
	       str.erase(str.begin(), str.end());
	       return accumulator;
	  }
     }
}
