#lang racket
; question 1
;TW = total weight
;(filter '(1 2 3 4) '(1.0 1.0 2.0 3.0 5.0 8.0 13.0))

(
 define (filter weights filterL)
(define TW (addWeights weights)) (define newFilterW (createNEW weights TW))
(calculateFilter newFilterW filterL )
)

; this creates the result list
(define (calculateFilter newFilterW filterL) 
    (if (null? filterL) '() (cons  (result newFilterW newFilterW filterL filterL)
                                 (append (calculateFilter newFilterW (cdr filterL))))
)
                                                         
                                                            )
 
; the following functions adds all the weights together to create the new filter denominator
(define (addWeights weight) (if (null? weight) (+ 0 0)
                                (+ (car weight) (addWeights (cdr weight)))))

; the following is to create the new filter weights after adding all the weights
(define (createNEW weights TW) (if (null? weights) '() (cons (/ (car weights) TW) (createNEW (cdr weights) TW))))


;this start generating the result data that will go into the list
(define (result newFilterW tempFilterW filterL tempFilterL) (
           cond
            ; if filter list is null then return an empty list
            ((null? filterL) '())
            ; else if the next part of the temporary filter weight is empty just multiply head of two lists
            ((null? (cdr tempFilterW)) (* (car tempFilterW) (car tempFilterL) ))
            ;else if the next part of the temporary filter list is empty just multiply head of two lists
            ((null? (cdr tempFilterL)) (* (car tempFilterW) (car tempFilterL) ))
            ;if non of those are happening then just recursevly add then call this function again
            (#t (+ (* (car tempFilterW) (car tempFilterL))
            (result newFilterW (cdr tempFilterW) filterL (cdr tempFilterL)))            
         )
      ;end conditional
  )  )




;question 2.1)
;(sumNumbers '(a 2 4 a b 5)) 

 (define (sumNumbers data) (addData data 0 '()))

   (define (addData data currentNumber currentLetters)
     (cond (
            (null? data)
            (cons currentLetters (cons currentNumber '())))    
            ((number? (car data)) (addData (cdr data)(+ currentNumber (car data)) currentLetters))
            (#t (addData (cdr data) currentNumber (appendList currentLetters (cons (car data) '()) ))))
             
  )

(define (appendList L1 L2)
(if (null? L1)
L2
(cons (car L1) (appendList (cdr L1) L2))))

; question 2.2)
;(quaternay 16) 
 (define (quaternay numberQ)
 
  (+ (modulo numberQ 4) (calculateDecimal numberQ (- numberQ (modulo numberQ 4)) ) ))

(define (calculateDecimal numberQ digitNR) (cond ( (eqv? (/ digitNR 4) 1) 10)
                                                                      ( (> (/ digitNR 4) 1) (* (calculateDecimal numberQ (/ digitNR 4)) 10) )
                                                                      (#t (+ 0 (- numberQ (modulo numberQ 4)))))
  
  

  )



;question 3
;(smallerCube 130)
(define cubeless(lambda (x b) (if(> b (* x x x))  (- b (* x x x)) 0)))

 (define smallerCube (lambda (b) (if (> b 0) (startsmallerCube b 1) '() ) ))

(define startsmallerCube (lambda (b x) (if (< b (* x x x)) (append '())
                   (appendList (cons (append (cons x '()) (cons (cubeless x b) '()) ) '()) (startsmallerCube b (+ x 1)))
                      )))


(define (restSum x)  (if (null? x) (+ 0)
 (+ (car (cdr (car x))) (restSum (cdr x)) ))
  )
;(showAllRestSum 1 20) 

(define showAllRestSum(lambda (x y) (if (< x (+ y 1)) (if (eqv? (modulo (restSum (smallerCube x)) 3) 0)
                               (appendList (cons (append (cons x '()) (cons (restSum (smallerCube x)) '()) ) '()) (showAllRestSum (+ x 1) y))
                              ; (appendList (showAllRestSum (+ x 1) y) '()))
                               (showAllRestSum (+ x 1) y) )
                                        (append '()))
)
                                        )