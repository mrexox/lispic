#include "evaluator.h"


namespace lispic {
     Symbol Evaluator::eval(Symbols& elements)
     {
	  eval_list(elements);
	  // if has just one symbol inside -> return it
	  // if has a list with something, try to call something
	  // NOTE: calling of () returns NIL, which is 0, "" and empty list
     }
     
     void Evaluator::eval_list(Symbols& elements)
     {
	  for (Symbols::iterator p = elements.begin();
	       p < elementd.end();
	       ++p)
	  {
	       if (p->type() == LIST) {
		    
		    eval_list( p->list() );
		    
	       } else if (p->type() == ATOM) {
		    
		    if (like_num(*p) || like_str(*p)) {
			 eval_symbol(*p);
		    } else {
			 send_to_env(*p);
		    }
	       } else {
		    // FIXME
		    // symbol was already initialized
		    // seems impossible
	       }
	       
	  }
     }
     
     bool Evaluator::like_num(Symbol& s)
     {
	  for(int i = 0; i < s.name().length(); ++i)
	  {
	       if ( !( isdigit(s.name()[i] || s.name()[i] == '.' ) ))
		    return false;
	  }
	  return true;
     }

     bool Evaluator::like_str(Symbol& s)
     {
	  if (s.name()[0] == '\"' && s.name()[s.name().length() - 1] == '\"')
	       return true;
	  return false;
     }
     
     void Evaluator::eval_symbol(Symbol& symbol)
     {
	  if ( like_str(symbol) )
	  {
	       std::string value = symbol.name();
	       value.pop_back();
	       value.erase(0, 1);
	       symbol.init(value);
	  } else {
	       try {
		    number n = std::stod(symbol.name());
		    symbol.init(n);
	       } catch (std::invalid_argument ia) {
		    throw eval_error(symbol.name()
				     + " is not a number but supposed to be so");
	       } catch (std::out_of_range oor) {
		    throw eval_error("Cannot convert to double: " + symbol.name());
	       }
	  }
     }

     void Evaluator::send_to_env(Symbol& symbol)
     {
	  Environment env = Environment::Get();
	  if ( !env.fulfill(symbol) )
	  {
	       throw eval_error("Symbol `" + symbol.name() + "` is unknown");
	  }
     }
}
