#include "reader.h"
#define SKIP_BLANKS(S) while( is_blank(S.peek()) ) {S.get();}
#define SKIP_SPACE(S) while( is_space(S.peek()) ) {S.get();}
#define SKIP_COMMENT(S) while( S.get() != LINEFEED);

namespace lispic
{
     bool Reader::is_space(const char& ch) const
     {
	  return ch == SPACE || ch == TAB;
     }
     
     bool Reader::is_blank(const char& ch) const
     {
	  return is_space(ch) || ch == LINEFEED;
     }
     
     bool Reader::finished(std::istream& in) 
     {
	  return in.eof() || in.fail();
     }

     Symbols Reader::read(std::istream& in, int method=FROM_CONSOLE)
     {
	  Symbols symbols;
	  if (method == FROM_FILE)
	  {
	       SKIP_BLANKS(in);
	  }
	  char ch;
	  while ( !finished(in))
	  {	       
	       switch (ch = in.get())
	       {
	       case QQ:
		    in.putback(ch);
		    symbols.push_back(read_string(in));
		    break;
	       case LP:
		    in.putback(ch);
		    symbols.push_back(read_list(in));
		    break;
	       case RP:
#ifdef STRICT
		    throw syntax_error("Unexpected ')'");
#endif
		    in.putback(ch);
		    break;
	       case COMMENT:

		    SKIP_COMMENT(in)
		    break;
	       case LINEFEED:
		    break;
	       default:
		    in.putback(ch);
		    symbols.push_back(read_symbol(in));
		    break;
	       }

	       if (method == FROM_CONSOLE) {
		    SKIP_SPACE(in)
		    if(in.peek() == LINEFEED) break;
	       } else {
		    SKIP_BLANKS(in)
	       }
	  }
	  return symbols;
     }

     Symbol Reader::read_atom(std::istream& in)
     {	       
	  switch (in.peek())
	  {
	  case QQ:
	       return read_string(in);
	  case LP:
	       return read_list(in);
	  case RP:
#ifdef STRICT
	       throw syntax_error("Unexpected ')' while reading list");
#elif
	       in.get();
#endif
	  default:
	       return read_symbol(in);
	  }
     }
     
     Symbol Reader::read_list(std::istream& in)
     {
	  Symbol symbol;
	  Symbols list;
	  
	  if (in.peek() != LP) throw syntax_error("Expected list but found not");

	  in.get(); // pop the '('

	  while(!in.eof() && !in.fail())
	  {
	       SKIP_BLANKS(in)
	       switch (in.peek())
	       {
	       case RP:
		    in.get();
		    return Symbol(list);
	       case COMMENT:
		    SKIP_COMMENT(in)
		    break;
	       default:
		    list.push_back(read_atom(in));
		    break;
	       }
	  }
	  throw read_error("<Input Error> or EOF occured");
     }
     
     Symbol Reader::read_symbol(std::istream& in)
     {	       
	  std::string name;
	  while ( !in.eof() && !in.fail() && !is_blank(in.peek()) )
	  {
	       switch (in.peek())
	       {
		    // Refactor me
	       case COMMENT: SKIP_COMMENT(in)
	       case LP:
	       case RP:		  
	       case QQ:
		    return Symbol(name);
		    break;
	       default:
		    name += in.get();
		    break;
	       }
	  }
	  #ifdef STRICT
	  if ( in.fail() ) throw read_error("<Input Fail> while reading in `read_symbol()`");
	  #endif
	  return Symbol(name);
     }

     Symbol Reader::read_string(std::istream& in)
     {
	  char ch;
	  std::string name = "\"";
	  in.get();
	  while ((ch = in.get()) != QQ && !in.eof() && !in.fail())
	       name += ch; 
	  if (in.eof() || in.fail()) {
	       throw read_error("Error while reading. <End Of File> or <Input Fail> cought.");
	  }
	  name += ch;
	  return Symbol(name);
     }
}
