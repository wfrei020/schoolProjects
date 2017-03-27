#lang racket
;Name: Walter Freire
;id: 6399015
;Assingment 4
;Question 1
;(mergeALot '((1 3 5) (2 4 6) (2 6 8)))
;(12345668)
;(mergeALot '((1 3 5) (2 0 6) (2 6 8) (3 1) (5 4 3 2 1 0) (1 5 9 13 17)))
; "ERROR: The following lists are not sorted: " (2 4 5) 

(define (mergeALot sortedLists) 
;check all List are sorted , if they are then begin merge else display lists that are not sorted
          (if (equal? (checkLists sortedLists 1) '())
              (mergeLists sortedLists)
          ( error sortedLists)))
;to display the lists that are not in order
(define (error sortedLists) (display "ERROR: The following lists are not sorted: ") (display
            (checkLists sortedLists 1)))
; to check for all lists to see if all are sorted, if they are then it return empty list else returns unsorted list number
(define (checkLists sortedLists n)
  (if (null? sortedLists) '()
(if (equal? (checksort (car sortedLists)) '()) (checkLists (cdr sortedLists) (+ n 1))
      (cons n (checkLists (cdr sortedLists) (+ n 1))))))

;check each individual list is sorted else return notsorted
(define (checksort list) (if (null? (cdr list))
                         '()
                         (if (<= (car list) (car (cdr list)))
                             (checksort (cdr list))
                             '(notSorted) )))



(define (mergeLists  sortedLists)( cond ((null? sortedLists) '())
                                        ;if list only has one list then display sorted list
                                        ((null? (cdr sortedLists)) sortedLists)
                                        ;if list only had two lists then merge both lists and display
                                        ((null? (cdr (cdr sortedLists)))  (mergetwo (car sortedLists) (car (cdr sortedLists)) ))
                                        ;otherwise just keep merging front two lists together
                                        (#t (mergeLists (cons(mergetwo (car sortedLists) (car (cdr sortedLists))) (cdr (cdr sortedLists)) )) )
                                      
                                  ))
 ; the following code snippet was taken from proffessors slides to implement a merge of two lists in question 2
(define (mergetwo L M)
(cond ( (null? L) M)
((null? M) L)
((< (car L)(car M))
(cons (car L)
(mergetwo (cdr L) M)))
(else (cons (car M)
(mergetwo L (cdr M))))))


;question 2
;(ourLog 0.5 0.00001)
;(ourLog 0.95 0.00001)
;(ourLog 0.0 0.001) 
(define (ourLog x e) (if (>= x 1) (display "please enter a number less than 1")
                         (if (<= x -1) (display " please enter a number greate than -1")
                             (ourLogN x e 2))))

(define (ourLogN x e n)
( if (>= e 1) (display "please enter a precision les than 1") (if (<= e 0) (display "please enter a precision greater than 0")
  (if (<= (abs (- (calculate x n) (calculate x (- n 1)))) e) (cons (calculate x n) (cons n '())) (ourLogN x e (+ n 1)))
))
  )

(define (calculate x i)
  (if (eq? i 1) (/ x 1)
  (+ (* (expt -1 (+ i 1)) (/ (expt x i) i)) (calculate x (- i 1)))))


; question 3
;(lca '(73 (31 (5 () ()) ()) (101 (83 () (97 () ())) (2016 () ()))) 97 2016)
;(lca '(73 (31 (5 () ()) ()) (101 (83 () (97 () ())) (2016 () ()))) 2016 97) 
;(lca '(73 (31 (5 () ()) ()) (101 (83 () (97 () ())) (2016 () ()))) 1 97) 
;(lca '(73 (31 (5 () ()) ()) (101 (83 () (97 () ())) (2016 () ()))) 5 31) 
;(lca '() 31 97) 

(define (lca T k1 k2) (cond
                        ((null? T) '())
                        ;check if key element root of tree is between key elements
                        ((and (>= (car T) k1)  (<= (car T) k2)) (if (and (search k1 T) (search k2 T))  (display T) '() )   )
                         ((and (<= (car T) k1) (>= (car T) k2))  (if (and (search k1 T) (search k2 T)) (display T) '())    )
                         ;if both elements are less than root then go left of tree
                         ((and (> (car T) k1) (> (car T) k2)) (lca (cadr T) k1 k2)    )
                         ;if both elements are greater than root then go right of tree
                         ( (and (< (car T) k1) (< (car T) k2)) (lca (caddr T) k1 k2)     )  
                         )
  )

; the following was taken from professors slides and used to implement question 3
; very little was modified
;used to search for key element in BST
(define search
(lambda (x t)
(cond
((null? t) #f)
((equal? x (car t)) #t)
((< x (car t)) (search x (cadr t)))
((< (car t) x) (search x (caddr t)))
(else #f)
)))

