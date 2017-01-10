= lispic - a small lisp interpreter

*** Supposed to be built on OO design with concrete responcability on each class given.

Consists of several main classes:
- Reader
- Evaluator
- Repository
- Symbol
- Function

Reader responces for reading code and wrapping it in Symbols.

Evaluator responces for controlling the process of evaluation.

Repository responces for symbols interpretation.

Symbol responces for keeping data inside.

Function responces for subroutines that may be called.

*** Terminology

NUMBER, STRING and FUNCTION are indeed ATOMs
only LIST is not atomic.

This behaviour is needed for reader to firstly deside, what symbols look like.
(Actually it's because in Symbols must be both atoms and lists, so I just suppose that a symbol may also be list. This dichotomy is an issue for further solution.)

*** Functions

Functions can be either builtin/user-defined or special forms. Special forms are not evaluated but called the same way as functions (via call(Symbols) method).

***

All builtins and specials are implemented in lib namespace
User-defined functions wrap into Symbol::Value and can be kept in Repository
