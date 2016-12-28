#include "reader.h"
#define skip_blanks(S) while( is_blank(S.peak()) ) {S.get();}

namespace lispic
{
     bool Reader::is_blank(const char& ch) const
     {
	  return !(std::isalnum(ch) || ch == LP || ch == RP || ch == QQ); 
     }
     
     bool Reader::finished(std::istream in)
     {
	  
     }

     Symbols Reader::read(std::istream in)
     {
	  char ch;
	  Symbols symbols;
	  if (in.eof()) {
	       Symbol symbol;
	       symbols.push_back(symbol);
	       return symbols;
	  }	  
	  /*
	    Needs to read a symbol or a list covered in a symbol
	   */
     }

     Symbol Reader::read_atom(std::istream in)
     {
	  skip_blanks(in)
	       
	  switch (in.peak())
	  {
	  case QQ:
	       return read_string(in);
	  case LP:
	       return read_list(in);
	  case RP:
	       #ifdef STRICT
	       throw syntax_error("Unexpected ')'");
	       #else
	       return Symbol(); // NIL
	       #endif
	  default:
	       return read_symbol(in);
	  }
     }
     
     Symbol Reader::read_symbol(std::istream in)
     {	       
	  char ch;
	  std::string name;
	  while ( !in.eof() && !in.fail() && !is_blank(ch = in.get()) )
	  {
	       switch (ch)
	       {
	       case LP:
	       case RP:		  
	       case QQ:
		    in.putback(ch);
		    return Symbol(name);
		    break;
	       default:
		    name += ch;
		    break;
	       }
	  }
	  #ifdef STRICT
	  if ( in.fail() ) throw std::exception("<Input Fail> while reading");
	  #endif
	  return Symbol(name);
     }

     Symbol read_string(std::istream in)
     {
	  char ch;
	  std::string name = "\"";
	  while ((ch = in.get()) != QQ && !in.eof() && !in.fail())
	  { name += ch; }
	  if (in.eof() || in.fail()) {
	       throw std::exception("Error while reading. <End Of File> or <Input Fail> cought.");
	  }
	  name += ch;
	  return Symbol(name);
     }
}
