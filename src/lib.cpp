#include "lib.h"

namespace lispic
{
     namespace lib
     {
	  
	  Symbol sum(Symbols& symbols)
	  {
	       Number res = 0;
	       for (Symbols::const_iterator p = symbols.begin();
		    p != symbols.end();
		    ++p)
	       {
		    res += p->value().number();
	       }
	       return Symbol(std::to_string(res), Symbol::Value(res));
	  }

	  Symbol subtract(Symbols& symbols)
	  {
	       Number res = symbols.begin()->value().number();
	       for (Symbols::const_iterator p = symbols.begin() + 1;
		    p != symbols.end();
		    ++p)
	       {
		    res -= p->value().number();
	       }
	       return Symbol(std::to_string(res), Symbol::Value(res));
	  }

	  Symbol product(Symbols& symbols)
	  {
	       Number res = 1;
	       for (Symbols::const_iterator p = symbols.begin();
		    p != symbols.end();
		    ++p)
	       {
		    res *= p->value().number();
	       }
	       return Symbol(std::to_string(res), Symbol::Value(res));
	  }
     
	  Symbol devide(Symbols& symbols)
	  {
	       Number res = symbols.begin()->value().number();
	       for (Symbols::const_iterator p = symbols.begin() + 1;
		    p != symbols.end();
		    ++p)
	       {
		    res /= p->value().number();
	       }
	       return Symbol(std::to_string(res), Symbol::Value(res));
	  }
     
	  Symbol print(Symbols& symbols)
	  {
	       for(Symbols::iterator p = symbols.begin();
		   p != symbols.end();
		   ++p)
	       {
		    std::cout << p->value();
		    if (p + 1 != symbols.end()) std::cout << ' ';
	       }
	       return Symbol();
	  }

	  Symbol null(Symbols& symbols)
	  {
	       return Symbol(symbols.front().value().type() == NIL);
	  }

	  Symbol _not(Symbols& symbols)
	  {
	       if (symbols.size() != 1)
		    throw lispic_error("`not` must be used like this: (not symbol)");
	       if (symbols.front().value().type() == NIL)
		    return Symbol(true);
	       else
		    return Symbol(false);
	  }
	  
	  Symbol more(Symbols& symbols)
	  {
	       if (symbols.size() < 2)
		    throw lispic_error("'more' must look like this: (> a b ...)");
	       for (Symbols::iterator p = symbols.begin() + 1;
		    p != symbols.end();
		    ++p)
	       {
		    if ((p-1)->value() <= p->value()) return Symbol(false);
	       }
	       return Symbol(true);
	  }
     
	  Symbol less(Symbols&);
	  Symbol equal(Symbols&);
     
	  Symbol println(Symbols& symbols)
	  {
	       Symbol s = print(symbols);
	       std::cout << std::endl;
	       return s;
	  }
     
	  Symbol concat(Symbols& symbols)
	  {
	       std::string res;
	       for (Symbols::const_iterator p = symbols.begin();
		    p != symbols.end();
		    ++p)
	       {
		    res += p->value().string();
	       }
	       return Symbol('\"' + res + '\"', Symbol::Value(res));
	  }
     
	  Symbol set(Symbols& symbols)
	  {
	       for (Symbols::iterator p = symbols.begin();
		    p < symbols.end();
		    p += 2)
	       {
		    Symbols s {*(p+1)};
		    Symbol tmpsym = Evaluator::Get().eval( s );

		    Repository::Get().variables.back()[p->name()] = tmpsym.value();
	       }
	       return symbols.back();
	  }

	  Symbol def(Symbols& symbols)
	  {
	       Symbol res;
	       for (Symbols::iterator p = symbols.begin();
		    p < symbols.end();
		    p += 2)
	       {
		    Symbols s {*(p+1)};
		    res = Evaluator::Get().eval( s );
		    Repository::Get().variables.back()[p->name()] = res.value();
	       }
	       return res;
	  }

     
	  Symbol lambda(Symbols& symbols)
	  {
	       Symbols body, signature;
	       body.assign(symbols.begin()+1, symbols.end());
	       signature = symbols.at(0).list();
	       UserFunction* uf = new UserFunction(signature, body);
	       return Symbol("lambda", uf);
	  }

	  Symbol if_statement(Symbols& symbols)
	  {
	       if (symbols.size() > 3 || symbols.size() < 2)
		    throw lispic_error("`if` statement must look like (if 'condition' 'then' 'else'");
	       Symbols condition { *(symbols.begin()) };
	       Symbol result = Evaluator::Get().eval( condition );
	       if (result.type() != NIL)
	       {
		    Symbols _then { *(symbols.begin()+1) };
		    return Evaluator::Get().eval( _then  );	      
	       } else if (symbols.size() == 3) {
		    Symbols _else { *(symbols.begin()+2) };
		    return Evaluator::Get().eval( _else  );	      
	       } else
		    return Symbol(false);
	  }

	  Symbol have(Symbols& symbols)
	  {
	       for (Symbols::iterator p = symbols.begin();
		    p != symbols.end();
		    ++p)
	       {
		    if (!Repository::Get().has(p->name())) return Symbol(false);
	       }
	       return Symbol(true);
	  }

     }
}
