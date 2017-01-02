#include "environments.h"

namespace lispic
{
     
     Environments::Environments()
     {
	  builtins["+"] = builtins["sum"] = sum;
	  builtins["def"] = def;
	  builtins["lambda"] = builtins["\\"] = lambda;
	  builtins["set"] = set;
	  builtins["print"] = print;
	  builtins["concat"] = concat;
     }

     bool Environments::fulfill(Symbol& sym)
     {
	  if (!builtins.fulfill(sym))
	       if (!user_defined.fulfull(sym))
		    if (!variables.fulfill(sym))
			 return false;
	  return true;
     }

     void Environments::set(std::string name, Symbol symbol)
     {
	  switch (symbol.type()) {
	  case NUMBER:
	  case STRING:
	  case NIL:
	       variables.set(name, symbol); break;
	  case FUNCTION:
	       user_defined.set(name, symbol.function()); break;
	  default:
	       throw exception("Can't set symbol `" + symbol.name() + "`");
	  }
     }

     Symbol sum(Symbols& symbols)
     {
	  Number res = 0;
	  for (Symbols::const_iterator p = symbols.begin();
	       p != symbols.end();
	       ++p)
	  {
	       res += p->number();
	  }
	  return Symbol(std::to_string(res)).init(res);
     }
     
     Symbol print(Symbols& symbols);
     Symbol concat(Symbols& symbols)
     {
	  std::string res;
	  for (Symbols::const_iterator p = symbols.begin();
	       p != symbols.end();
	       ++p)
	  {
	       res += p->string();
	  }
	  return Symbol(res).init(res);
     }
     Symbol def(Symbols& symbols);
     Symbol set(Symbols& symbols);
     Symbol lambda(Symbols& symbols)
     {
	  /*
	    UserFunction with no name
	    (lambda (arg1 arg2 ...) (body...))
	    symbols:
	      symbols - args
	      symbols - body:
	        
	   */
     }
}
