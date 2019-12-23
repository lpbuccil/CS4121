#lang racket

;;Lucas Buccilli
;;CS4121 Project 5
;;12/10/2019

;;1
(define (last a L)
  (local ((define (helper a L n x)
       	(cond
                ;;end of list
         	[(null? L) n]
                ;;atom is element, update current index
         	[(eq? (first L) a) (helper a (rest L) x (+ x 1))]
                ;;atom is not element
         	[else (helper a (rest L) n (+ x 1))]
         	)
       	))
	(helper a L -1 0)
	)
 )

;;2
(define (wrap M)
  (if (null? M)
      ;;end of list
      M
      ;;take the first element and wrap it
      (cons (cons (first M) '())(wrap (rest M)))
  )
)

;;3

(define (count-parens-all M)
  (local ((define (helper a M)
            (cond
              ;;if list is empty add 2 because its a list
             [(null? M) (+ a 2)]
             ;;first atom is a list, look in it
             [(list? (first M)) (+ (helper a (first M)) (helper a (rest M)))]
             ;;rest atom is a list, look in it
             [(list? (rest M)) (helper a (rest M))]
             ;;M is an atom
             [else (+ a 2)]
            )
          ))
    (helper 0 M)
    )
)

;;4
(define (insert-right-all new old M)
  (cond
    ;;list is smpty
    [(null? M) M]
    ;;first is a list, look in it
    [(list? (first M)) (cons
                        (insert-right-all new old (first M))
                        (insert-right-all new old (rest M))
                        )
                       ]
    ;;first is equal to element, add new after
    [(eq? (first M) old) (cons
                          (first M)
                          (cons
                           new
                           (insert-right-all new old (rest M))
                           )
                          )
                         ]
    ;;atom is not the element we are looking for
    [else (cons
           (first M)
           (insert-right-all new old (rest M))
           )
          ]
  )
)

;;5
(define (invert M)
  (cond
    [(null? M) M]
    ;;first is not a pair, but a list
    [(list? (first M)) (cons
                        (invert (first M ))
                        (invert (rest M))
                        )
                       ]
    ;;invert pair
    [else (append (rest M) (cons
                            (first M)
                            '()
                            ) ) ]
  )
)

;;6
(define (filter-out pred L)
  (cond
    [(null? L) L]
    ;;pred is true, dont copy
    [(pred (first L)) (filter-out pred (rest L))]
    ;;pred is false, add to list
    [else (cons
           (first L)
           (filter-out pred (rest L)))]
  )
)

;;7
(define (summatrices M1 M2)
  ;;for each row, and each element in each row, add them
  (map (lambda (M1 M2) (map + M1 M2)) M1 M2)
)

;;8
(define (swapper a1 a2 M)
  (cond
    [(null? M) M]
    ;;m is an atom
    [(not (list? M))
     (cond
       [(eq? M a1) a2]
       [(eq? M a2) a1]
       [else M]
      )
     ]
    ;;m is a list
    [else (cons (swapper a1 a2 (first M)) (swapper a1 a2 (rest M)))]
  )
)

;;9

(define (flatten M)
  (cond
    [(null? M) M]
    [(list? M)
     (if (null? (first M))
           ;;first is empy, remove it
           (flatten (rest M))
           ;;first is not empy, add it
           (append (flatten (first M)) (flatten (rest M)))
           )
     ]
    [else (cons
           M
           '())]
   )
)

;;10

(define (binary-tree-insert T n)
  (local ((define (helper L N R m)
            (cond
              ;;at a leaf,create a new node
              [(null? N) (cons '() (cons m '(())))]
              ;;go right
              [(> m N) (cons
                        L
                        (cons
                         N
                         (cons
                          (binary-tree-insert (first R) m)
                          '())))]
              ;;go left
              [else (cons
                     (cons
                      (binary-tree-insert (first L) m)
                      '())
                     (cons
                      N
                      R))]
              )
            ))
    (if (null? T)
        ;;leaf node
        (helper null null null n)
        (helper (first T) (first(rest T)) (rest(rest T)) n)
      
        )
    )
)

;;11

(define (abstract-fn f g n)
  (local
    ((define (help a M)
       (cond
         [(null? M) (f)]
         [(not (pair? (first M))) (g a M)]
         [else (n a M)]
         )
       ))
    help
    )
  )

(define rember* (abstract-fn
                  (lambda() '()) 
                  (lambda (a M)
                    (if (eq? a (first M)) (rember* a (rest M))
                        (cons (first M) (rember* a (rest M)))
                        )
                    ) 
                  (lambda (a M)
                    (cons (rember* a (first M)) (rember* a (rest M)))
                    )
                  )
  )
(define (depth M) ((abstract-fn
                    (lambda () 1) 
                    (lambda (a M)
                      (depth (rest M))
                      ) 
                    (lambda (a M)
                      (max (add1 (depth (first M)))
                           (depth (rest M))
                           )
                      ) 
                    ) -1 M)
  )



