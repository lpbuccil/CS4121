; problem 1
(define (last a L)
  (local (
          (define (last-help a L base)
           (cond 
            [(empty? L) -1]
            [(eq? a (first L)) (max (last-help a (rest L) (add1 base)) base)]
            [else (last-help a (rest L) (add1 base))]
           )
          )
         )
    (last-help a L 0)
  )  
)  

; problem 2
(define (wrap M)
  (cond
    [(empty? M) '()]
    [(not (pair? (first M))) (cons (list (first M)) (wrap (rest M)))]
    [else (cons (wrap (first M)) (wrap (rest M)))]))
        

; problem 3
(define (count-parens-all M)
  (cond
   [(empty? M) 2]
   [(pair? (first M)) (+ (count-parens-all (first M)) (count-parens-all (rest M)))]
   [(null? (first M)) (+  2 (count-parens-all (rest M)))]
   [else (count-parens-all (rest M))]
  )
)

; problem 4
(define (insert-right-all new old L)
  (cond
    [(null? L) '()]
    [(eq? (first L) old) (cons old (cons new (insert-right-all new old (cdr L))))]
    [(not (pair? (car L))) (cons (first L) (insert-right-all new old (cdr L)))]
    [else (cons (insert-right-all new old (car L))
                (insert-right-all new old (cdr L)))]))

; problem 5
(define (invert M)
  ( if (empty? M) 
       '()
       (cons (cons (second (first M)) (cons (first (first M)) '())) (invert (rest M)))
  )
)

; problem 6
(define (filter-out pred L)
  (cond
    [(empty? L) '()]
    [(not (pred (first L))) (cons (first L) (filter-out pred (rest L)))]
    [else (filter-out pred (rest L))]))

; problem 7
(define (summatrices M1 M2)
  (local ((define (sumrow L1 L2)
            (cond [(null? L1) '()]
                  [(null? L2) '()]
                  [else (cons (+ (first L1) (first L2))
                              (sumrow (rest L1) (rest L2)))]
            )
          ))
    (cond [(null? M1) '()]
        [(null? M2) '()]
        [else (cons (sumrow (first M1) (first M2))
               (summatrices (rest M1) (rest M2)))
         ]
        )
    )
  )
; problem 8
(define (swapper a1 a2 M)
  (cond
    [(empty? M) '()]
    [(eq? a1 (first M)) (cons a2 (swapper a1 a2 (rest M)))]
    [(eq? a2 (first M)) (cons a1 (swapper a1 a2 (rest M)))]
    [(not (pair? (first M))) (cons (first M) (swapper a1 a2 (rest M)))]
    [else (cons (swapper a1 a2 (first M))
                (swapper a1 a2 (rest M)))]))
; problem 9
(define (flatten M)
  (cond
    [(empty? M) '()]
    [(not (list? (first M))) (cons (first M) (flatten (rest M)))]
    [else (append (flatten (first M)) (flatten (rest M)))]))

; problem 10
(define (binary-tree-insert T n)
   (local ( (define (newnode n)
              (cons '() (cons n (cons '() '()))))
          )
     (cond
       [(empty? T) (newnode n)]
       [(> n (second T)) (cons (first T) (cons (second T) (cons (binary-tree-insert (third T) n) '())))]
       [else (cons (binary-tree-insert (first T) n) (rest T))]
     )    
   )  
)  

; problem 11
(define (abstract f g base)
  (local ((define (helper a M)
            (cond
              [(null? M) base]
              [(not (pair? (first M))) (f a M)]
              [else (g a M)])))
    helper))

(define rember* (abstract (λ (a M) (if (eq? a (first M))
                                       (rember* a (rest M))
                                       (cons (first M) (rember* a (rest M)))))
                          (λ (a M) (cons (rember* a (first M)) (rember* a (rest M))))
                          '()))

(define depth-2 (abstract (λ (a M) (depth (rest M)))
                          (λ (a M) (max (add1 (depth (first M)))
                                        (depth (rest M))))
                          1))

(define (depth M)
  (depth-2 '() M))