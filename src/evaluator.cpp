#include "evaluator.h"

namespace lispic {
     Symbol Evaluator::eval(Symbols& program)
     {
	  Symbol result;
	  for (Symbols::iterator p = program.begin();
	       p < program.end();
	       ++p)
	  {
	       if (p->value().type() == LIST)
	       {
		    result = do_this_list(p->value().list());
	       } else {
		    result = eval_symbol(*p);
	       }
	  }
	  return result;
     }
     
     Symbol Evaluator::eval(Symbol& symbol)
     {
	  return eval_symbol(symbol);
     }
     
     Symbol Evaluator::do_this_list(Symbols& list)
     {
	  if (list.empty()) return Symbol();
	  if ( is_special(list.begin()->name()) )
	  {
	       list.begin()->set( Repository::Get().get_special( list.begin()->name() ));
	       return make_function_call( list );
	  } else {
	       Symbols evaled_list = eval_list( list ); 
	       return make_function_call( evaled_list );
	  }
     }
	  
     Symbols Evaluator::eval_list(Symbols empty_symbols)
     {
	  Symbols fulfilled;
	  for (Symbols::iterator p = empty_symbols.begin();
	       p < empty_symbols.end();
	       ++p)
	  {
	       if (p->value().type() == LIST) {
		    
		    fulfilled.push_back( do_this_list( p->value().list() ));
		    
	       } else {		    
		    fulfilled.push_back( eval_symbol(*p) );
	       }
	  }
	  return fulfilled;
     }
     
     Symbol Evaluator::eval_symbol(Symbol& symbol)
     {
	  if (like_num(symbol)) {
	       return eval_to_number(symbol);
	  } else if (like_str(symbol)) {
	       return eval_to_string(symbol);
	  } else {
	       return get_from_env(symbol.name());
	  }	         
     }
     
     bool Evaluator::like_num(Symbol& s)
     {
	  for(unsigned int i = 0; i < s.name().length(); ++i)
	  {
	       if ( !( isdigit(s.name()[i]) || s.name()[i] == '.' ))
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
	  
     Symbol/*¿&?*/ Evaluator::eval_to_number(Symbol& symbol)
     {
	  try {
	       Number num = std::stod(symbol.name());		    
	       symbol.set(Symbol::Value(num));		    
	  } catch (const std::invalid_argument& ia) {
	       throw eval_error(symbol.name()
				+ " is not a number but supposed to be so");
	  } catch (const std::out_of_range& oor) {
	       throw eval_error("Cannot convert to double: " + symbol.name());
	  }
	  return symbol;
     }
	  
     Symbol/*¿&?*/ Evaluator::eval_to_string(Symbol& symbol)
     {
	  std::string str = symbol.name();
	  str.pop_back();
	  str.erase(0, 1);
	  symbol.set( Symbol::Value(str) );
	  return symbol;
     }

     Symbol Evaluator::get_from_env(std::string name)
     {
	  Repository& repository = Repository::Get();
	  if ( !repository.has(name) )
	  {
	       
	       throw eval_error("Symbol `" + name + "` is unknown");
	  }
	  return Symbol(name, repository.get(name));
     }

     Symbol Evaluator::make_function_call(Symbols& list)
     {
	  // The first symbol is supposed to be a function
	  // ПОЛИМОРФИЗМ
	  Function* pf = list.front().value().pfunction();
	  Symbols args;
	  args.assign(list.begin()+1, list.end());
	  return pf->call(args);
     }

     bool Evaluator::is_special(std::string name)
     {	  
	  return Repository::Get().has_special(name);
     }
}
