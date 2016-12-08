#include "builtins.h"
using namespace lispic;
using namespace std;

number plus(numbers args)
{
     number res = 0;
     for(numbers::iterator p = args.begin(); p != args.end(); ++p) {
	  res += *p;
     }
     return res;
}

number minus(numbers args)
{     
     number res = 0;
     for(numbers::iterator p = args.begin(); p != args.end(); ++p) {
	  res -= *p;
     }
     return res;
}

number product(numbers args)
{
     number res = 1;
     for(numbers::iterator p = args.begin(); p != args.end(); ++p) {
	  res *= *p;
     }
     return res;
}

number divide(numbers args)
{
     numbers::iterator p = args.begin();
     number res = *p++;
     while (p != args.end())
     {
	  res /= *p++;
     }
     return res;
}

number power(numbers args) // a ^ b
{
     if (args.size() != 2) 
	  throw bad_args("POWER: wrong number of arguments!");
     numbers::iterator num = args.begin();
     return pow(*num, *(++num));
}

static const map<string, num_func> NUM_FENV =
     {
	  {  "+", &plus },
	  {  "-", &minus},
	  {  "*", &product},
	  {  "/", &divide},
	  {  "^", &power},
     };
