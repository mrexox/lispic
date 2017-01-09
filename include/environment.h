#pragma once
#include "stdafx.h"

namespace lispic
{
     template<class K, class V>
     class Environment : public std::map<K, V>
     {	  
	  
     public:
	  virtual V set(K&, V&);
	  virtual V get(K&);
	  virtual bool has(K&);
//	  virtual void unset(K&);
     };

     class not_found_error : public lispic_error
     {
     public:
	  not_found_error(std::string msg)
	       : lispic_error(msg) {}
     };

     // -- Methods Realization-- //
     template<class K, class V>
     bool Environment<K, V>::has(K& key)
     {
	  typename std::map<K, V>::iterator i = this->find(key);
	  if (i != this->end()) 
	       return true;
	  return false;
     }
     
     template<class K, class V>
     V Environment<K, V>::set(K& key, V& value)
     {
	  (*this)[key] = value;
	  return value;
     }

     template<typename K, typename V>
     V Environment< K,  V>::get(K& key)
     {
	  typename std::map<K, V>::iterator i = this->find(key);
	  if (i != this->end()) {
	       return i->second;
	  } else {
	       std::stringstream ss;	// for better output
	       ss << key;
	       throw not_found_error("Environment doesn't have " + ss.str() ); // CHECK
	  }
     }
}
