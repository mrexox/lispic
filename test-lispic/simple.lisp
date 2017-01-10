(def pi 3.14)
(def length (lambda (r)
	      (def pi 3.14159265359)
	      (println "pi:" pi)
	      (* 2 pi r)))

(println "Length of circle with R=5 is: " (length 5))

(println (/ 123 8 (+ 8 0.90) (- 12 0.123) (* 1.1 1.1))) ; 0.1202079

(if (have pi)
    (println "Pi is set:" pi)
    (println "Pi is unknown"))

(def f (lambda (x)
	 (if (not (> x 12))
	     (println x "<= 12")
	     (println x "> 12"))))
(f 11)
(f 12)
(f 13)
(f 14)
