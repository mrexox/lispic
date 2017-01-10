;; Test defining different envieonments
(def pi 3.14)
(def length (lambda (r)
	      (def pi 3.14159265359)
	      (println "pi:" pi)
	      (* 2 pi r)))

(println "Length of circle with R=5 is: " (length 5))

;; Test simple calculations
(println (/ 123 8 (+ 8 0.90) (- 12 0.123) (* 1.1 1.1))) ; 0.1202079

;; Test ability to check if symbols exist
(if (have pi)
    (println "Pi is set:" pi)
    (println "Pi is unknown"))
(undef pi)
(println "Undefining pi")
(if (have pi)
    (println "Pi is set:" pi)
    (println "Pi is unknown"))

;; Test conditions
(def f (lambda (x)
	 (if (not (> x 12))
	     (println x "<= 12")
	     (println x "> 12"))))
(f 11)
(f 12)
(f 13)
(f 14)

;; Test independance of different environments
(def x 56)
(def f (lambda (x) (set x 89)
	       (println x)))
(f 12)
(println x)

;; Test cycles
(def +1 (lambda (x) (+ x 1)))
(def ! (lambda (x)
	 (def res 1)
	 (cycle (i 1 (+1 i))
		(> i x)
		(set res (* res i)))
	 res))
(cycle (num 0 (+1 num))
       (> num 10)
       (println (! num)))
	    
