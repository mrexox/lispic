(def test (lambda (what) (println "==== Test" what "===="))) 
;; Test defining different environments
(test "different environments")
(println "Outside pi:" (def pi 3.14))
(def length (lambda (r)
	      (def pi 5)
	      (println "Inside pi:" pi)
	      (* 2 pi r)))

(println "Length of circle with R=5 is: " (length 5))
(println "True length of circle with R=5 is: " (* 2 pi 5))
(println)

;; Test simple calculations
(test "simple calculations")
(println "Calculated:" (/ 123 8 (+ 8 0.90) (- 12 0.123) (* 1.1 1.1))) ; 0.1202079
(println "Must be:" 0.1202079)
(println)
;; Test ability to check if symbols exist
(test "ability to check if symbol exists")
(if (have pi)
    (println "Pi is set:" pi)
    (println "Pi is unknown"))
(undef pi)
(println "Undefining pi")
(if (have pi) ; Variable
    (println "Pi is set:" pi)
    (println "Pi is unknown"))
(if (have undef) ; Special
    (println "I can undefine symbol (t)")
    (println "Specials can be either variables or special functions funny bug o.o!!!"))
(if (have +) ; Builtin
    (println "I can sum number! (t)")
    (println "I cannot sum numbers! OMG!!!"))
(println)
;; Test conditions
(test "conditions")
(def f (lambda (x)
	 (if (not (> x 12))
	     (println x "<= 12")
	     (println x "> 12"))))
(f 11)
(f 12)
(f 13)
(f 14)
(println)
;; Test independance of different environments
(test "independance of different environments")
(def x 56)
(def f (lambda (x) (set x 89)
	       (println x)))
(f 12)
(println x)
(println)
;; Test cycles
(test "cycles")
(def +1 (lambda (x) (+ x 1)))
(def ! (lambda (x)
	 (def res 1)
	 (cycle (i 1 (+1 i))
		(> i x)
		(set res (* res i)))
	 res))

(cycle (num 0 (+1 num))
       (> num 10)
       (println "Factorial of" num "is" (! num)))
(println)
;; Test difficult conditions
(test "different conditions")
(def decide (lambda (x) (if (equal x 1)
			    (println "AAAA")
			    (if (equal x 2)
				(println "BBBB")
				(println "Oh, something else...")))))
(decide 1)
(decide 2)
(decide 3)
(println)
;; Test equal function
(test "equal function")
(if (not (equal t t))
    (println "t != t")
    (println "t == t"))

(if (null nil)
    (println "nil is null")
    (println "nil is NOT null"))

(if (null ())
    (println "() is null")
    (println "() is NOT null"))
(println)
;; Test  map function
(test "map function")

(def lst (list 12 23 34 54 34 54 23 56 6  43 34 54 23 12))
(def even (lambda (x) (if (equal (% x 2) 0) t nil)))

(map (lambda (x) (if (even x)
		     (println x "is even")
		     (println x "is odd")))
     lst)

(println)
