## lispic - a smallest lisp interpreter
Lispic gets an input from stdin or a file:
```
$ lispic filename
$ lispic
```
If it meets a symbol, it tries to evaluate it.
If it means a list like `(a1 a2 a3)` it tries to call `a`' on `(a2 a3)`

## Environment
There are 2 global environments: BUILTINS and SPECS.

BUILTINS:
	Functions that are implemented in the system, called from c++.
	Some of them:
	- +
	- -
	- /
	- *
	- concat
	- atomp
	- listp
	- null
	- funcp
	- map ; should I implemet it?
	
SPECS:
	Special forms like `if` and `lambda` that do some work for
	inner things (adding a new variable or conditions.
	
	For instance:
	- if
	- set
	- lambda
	- quote
	- function

The enother environment object is an ENV stack (but list) of environments, that can be passed to a function so it can make it's own functions and variables unseed from outside. 
!Functions and variables lay in one environment so they can't be both func and var!

Before calling a function the 'call' sub fills the inner environment with passed arguments. It evaluates the symbol and links it with the corresponding function-defined symbol.

## Evaluating
	
## Data manipulating

**Reader** - creates symbols and lists
**S_expression** - manipulates symbols and lists
**Environment** - deletes symbols and lists
