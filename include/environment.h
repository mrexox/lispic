#pragma once
#include "stdafx.h"
#include "symbol.h"

namespace lispic
{
     class Symbol;
     
     template<typename Key, typename Value>
     class Environment
     {
	  std::map<Key, Value> env;
     public:
	  bool fulfill(Symbol&);
	  void set(Key&, Value&);
     };     

     /*
     template<typename Key, typename Value>
     Symbol Environment<Key, Value>::set(Key key, Value value)
     {
	  env[key] = value;
     }

     template<typename Key, typename Value>
     bool Environment< Key,  Value>::fulfill(Symbol& symbol)
     {
	  std::map<Key, Value>::iterator i = env.find(symbol.name());
	  if (i != env.end()) {
	       symbol.init(*i);
	       return true;
	  } else {
	       return false;
	  }
     }
     */
}
