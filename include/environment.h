#pragma once
#include "stdafx.h"
#include "symbol.h"

namespace lispic
{
     template<Key, Value>
     class Environment
     {
	  std::map<Key, Value> env;
     public:
	  bool fulfill(Symbol&);
	  void set(Key&, Value&);
     };     
}

Symbol Environment<Key, Value>::set(Key key, Value value)
{
     env[key] = value;
}

bool Environment<Key, Value>::fulfill(Symbol& symbol)
{
     map<Key, Value>::iterator i = env.find(symbol.name());
     if (i != env.end()) {
	  symbol.init(*i);
	  return true;
     } else {
	  return false;
     }
}
