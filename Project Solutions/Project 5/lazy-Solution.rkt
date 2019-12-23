(define (f nm1 nm2)
  (+ (* 2 nm1) (* 3 nm2)))

(define f-list (cons 1 (cons 2 (cons 3 (map f f-list (rest (rest f-list)))))))
