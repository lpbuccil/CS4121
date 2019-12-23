#lang lazy

;;12
;;(!! (take 5 lazy-fn))

(define lazy-fn (cons
                 1
                 (cons
                  2
                  (cons
                   3
                   (map funct lazy-fn (rest(rest lazy-fn)))
                   )
                  )
                 )
  )

(define (funct a b)
  (+ (* 3 b) (* 2 a))
  )