## lispic - a small lisp interpreter

simply run
 For interactive mode
`$ ./lispic -i`

 For file interpreting
`$ ./lispic /directory/file-name.lisp`

 For fast evaluating
`$ ./lispic -e '(+ 2017 (/ 90 5))'`

## Language definition 

This is learning project. My aim was not to make a fully featured language but a simple lisp-like interpreter. Just for fun.
```
; - stays for comments. The string after `;` is ignored

Functions: +, -, /, %, *, concat, print, println - do what they used to do

(def a 100) ; defining a variable
(lambda (x) (+ x 1)) ; creating a function that takes 1 argument
(def +1 (lambda (x) (+ x 1))) ; defining an increment

(if confition*
    then*
    else*	) ; condition with else clause
;; or
(if condition*
    then*) ; condition without else clause

(cycle (var 0 (+1 var))
       (> var 12)
       (println var)) ; cycle, simple as piece of bread

(have f) ; check if symbol f exist in current context
(null ()) ; check if symbol is null

(list 1 2 3 4 5 "string") ; creating list
(def *list* (list 1 23 4 5))
(car *list) ; returns a copy of first element of *list*
(cdr *list*) ; returns a list except first element
(map f *list*) ; simple mapping through list with function f (that takes 1 argument)

(load "/dir/file-name.lisp") ; evaluates the file, returns nil if succeed (t otherwise)
```
## That's it
