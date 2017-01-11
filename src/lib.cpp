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
		    if (p->type() != NUMBER)
			 throw call_error("+: " + p->name() + " is not a number!");
		    res += p->value().number();
	       }
	       return Symbol(std::to_string(res), Symbol::Value(res));
	  }

	  Symbol modul(Symbols& symbols)
	  {
	       if (symbols.size() != 2)
		    throw call_error("%: must have 2 argument");
	       Number res = static_cast<int>(symbols.begin()->value().number())
		    % static_cast<int>((symbols.begin() + 1)->value().number());
	       return Symbol(std::to_string(res), Symbol::Value(res));
	  }
	  
	  Symbol subtract(Symbols& symbols)
	  {
	       if (symbols.size() == 0)
		    throw call_error("-: must have at least 1 argument");

	       Number res = symbols.begin()->value().number();
	       if (symbols.size() == 1) {
		    res = -res;
		    
	       } else {
		    
		    for (Symbols::const_iterator p = symbols.begin() + 1;
			 p != symbols.end();
			 ++p)
		    {
			 if (p->type() != NUMBER)
			      throw call_error("-: " + p->name() + " is not a number!");
			 res -= p->value().number();
		    }
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
		    if (p->type() != NUMBER)
			 throw call_error("*: " + p->name() + " is not a number!");
		    res *= p->value().number();
	       }
	       return Symbol(std::to_string(res), Symbol::Value(res));
	  }
     
	  Symbol devide(Symbols& symbols)
	  {
	       if (symbols.size() == 0)
		    throw call_error("/: must have at least 1 argument");
	       Number res = symbols.begin()->value().number();
	       for (Symbols::const_iterator p = symbols.begin() + 1;
		    p != symbols.end();
		    ++p)
	       {
		    if (p->type() != NUMBER)
			 throw call_error("/: " + p->name() + " is not a number!");
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
		    throw call_error("`not` must be used like this: (not symbol)");
	       if (symbols.front().value().type() == NIL)
		    return Symbol(true);
	       else
		    return Symbol(false);
	  }

	  Symbol equal(Symbols& symbols)
	  {
	       for (Symbols::iterator one = symbols.begin();
		    one != symbols.end();
		    ++one)
	       {
		    for (Symbols::iterator two = one;
			 two != symbols.end();
			 ++two)
		    {
			 if (one->value() != two->value()) return Symbol(false);
		    }
	       }
	       return Symbol(true);
	  }
	  
	  Symbol more(Symbols& symbols)
	  {
	       if (symbols.size() < 2)
		    throw call_error("'more' must look like this: (> a b ...)");
	       for (Symbols::iterator p = symbols.begin() + 1;
		    p != symbols.end();
		    ++p)
	       {
		    if (p->type() != NUMBER)
			 throw call_error(">: " + p->name() + " is not a number!");
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
	  
	  Symbol list(Symbols& symbols)
	  {
	       return Symbol(symbols);
	  }

	  Symbol car(Symbols& symbols)
	  {
	       if (symbols.size() != 1)
		    throw call_error("car: must be used like this (car list)");
	       return *symbols.begin()->value().list().begin();
	  }
	  
	  Symbol cdr(Symbols& symbols)
	  {
	       if (symbols.size() != 1)
		    throw call_error("cdr: must be used like this (car list)");
	       Symbols& lst = symbols.begin()->value().list();
	       Symbols cdrs; cdrs.assign(lst.begin()+1, lst.end());
	       return Symbol(cdrs);
	  }
	  
	  Symbol map(Symbols& symbols)
	  {
	       // ПОЛИМОРФИЗМ
	       Function* function = symbols.begin()->value().pfunction();
	       Symbols lst = (symbols.begin() + 1)->value().list();
	       Symbols res;
	       for (Symbols::iterator p = lst.begin();
		    p != lst.end();
		    ++p)
	       {
		    Symbols args { *p };
		    res.push_back(function->call(args));
	       }
	       return Symbol(res);
	  }
	  
	  Symbol concat(Symbols& symbols)
	  {
	       std::string res;
	       for (Symbols::const_iterator p = symbols.begin();
		    p != symbols.end();
		    ++p)
	       {
		    if (p->type() != STRING)
			 throw call_error("concat: " + p->name() + " is not a string!");
		    res += p->value().string();
	       }
	       return Symbol('\"' + res + '\"', Symbol::Value(res));
	  }
     
	  Symbol set(Symbols& symbols)
	  {
	       Repository& rep = Repository::Get();
	       Symbol tmpsym;
	       for (Symbols::iterator sym = symbols.begin();
		    sym < symbols.end();
		    sym += 2)
	       {
		    Symbols s {*(sym+1)};
		    tmpsym = Evaluator::Get().eval( s );
		    std::string name = sym->name();
		    for (Repository::Variables::reverse_iterator env = rep.variables.rbegin();
			 env != rep.variables.rend();
			 ++env)
		    {
			 if (env->has(name))
			 {
			      (*env)[name] = tmpsym.value();
			      break;
			 }
		    }
	       }
	       return tmpsym;
	  }

	  Symbol def(Symbols& symbols)
	  {
	       Symbol res;
	       std::string not_variables;
	       Evaluator& ev = Evaluator::Get();
	       for (Symbols::iterator p = symbols.begin();
		    p < symbols.end();
		    p += 2)
	       {
		    Symbols s {*(p+1)};
		    res = ev.eval( s );
		    if (ev.like_num(*p) || ev.like_str(*p)) {
			 not_variables += p->name() + " ";
			 continue;
		    }
		    Repository::Get().variables.back()[p->name()] = res.value();
	       }
	       if ( not_variables.length() ) {
		    throw call_error("def: " + not_variables + "do not look like variables. They were not defined.");
	       }
		    
	       return res;
	  }

	  Symbol undef(Symbols& symbols)
	  {
	       Symbol last_hope_symbol;
	       for(Symbols::iterator p = symbols.begin();
		   p != symbols.end();
		   ++p)
	       {
		    std::string name = p->name();
		    if (Repository::Get().variables.back().has(name))
		    {
			 last_hope_symbol.set(name, Repository::Get().variables.back().get(name));
			 Repository::Get().variables.back().erase(name);
		    }
	       }
	       return last_hope_symbol;
			
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
		    throw call_error("`if` statement must look like: (if 'condition' 'then' 'else'");
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

	  Symbol cycle(Symbols& symbols)
	  {
	       if (symbols.size() < 3)
		    throw call_error("`cycle` must look like: (cycle (var 0 +1) (> var 10) body*)");
	       Repository::VariablesEnvironment venv;
	       Repository& rep = Repository::Get();
	       Evaluator& ev = Evaluator::Get();
	       Symbol::Value init = symbols.front().value();
	       if (init.type() != LIST)
		    throw call_error("cycle: `initialization list` expected as first argument");
	       if (init.list().size() != 3)
		    throw call_error("cycle: initialization list must look like: (var beg incf)");
	       
	       std::string varname = init.list().begin()->name();
	       Symbols variable  { *(init.list().begin() + 1) };
	       
	       venv[varname] = ev.eval( variable ).value();
	       
	       Symbols function { *(init.list().begin() + 2) };

	       Symbols condition  { *(symbols.begin() + 1) };
	       Symbols body; body.assign(symbols.begin() + 2, symbols.end());
	       Symbol result;
	       
	       rep.variables.push_back(venv);
	       while( ev.eval(condition).value().type() == NIL)
	       {
		    result = ev.eval(body);
		    rep.set(varname, ev.eval(function).value());
	       }
	       rep.variables.pop_back();
	       return result;
	  }
     }
}
