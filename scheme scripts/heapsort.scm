
; CSI 3120 Assignment 1 Question 1

; Student Name: Walter Freire

; Student Number: 6399015

; Student Email: wfrei020@uottawa.ca

;(heapsort '(1 3 4 2 6))

;In the code I have now realized i could of done a few things simpler, due to time i can't fix or modify it but the code works well either way


;define the function heapsort

(define (heapsort a) (cond ((null? a) a) ((null? (cdr a)) a) (#t (sort (heapify a (length a)) (length a) (inOrder (cdr a) (car a))))) )

;due to a bug in my program when ever the list starts of with the smallest number at the beginning it will
;switch with the second value but will sort the rest eg (heapsort '(1 3 4 2 6)) --> '(2 1 3 4 6)
;Im not sure where it is but i was able to fix that problem by starting my sorting index at 2
; if it starts with he smallest number in the list AND index 1 if the smallest is not the first in the list

;the following functions is used in my code to check if the first value is the smallest in the list and will send
; the starting index to my sort function

(define (inOrder list1 first) (cond ((null? list1) 2) ((> first (car list1)) 1 ) (#t ( inOrder (cdr list1) first))))

;using recursion this function will sort the heap using the help of siftdown function

(define (sort heap count var ) 
	(if 	(> count var)							;condition
		(sort (siftdown (swap heap heap count 1) 1 (- count 1)) (- count 1) var) ;true
		 heap							;false
	) 	
 ;print the heap
)
;-----------------------------SWAPPING TWO NUMBERS IN A LIST (STATUS SUCCESSFUL)---------------------------------
; algorithm to swap two numbers in a list and return a list


(define (swap heapStart heapMod index1 index2)	 (startSwap (startSwap heapMod index1 (getVal heapStart index2)) index2 (getVal heapStart index1))	)

; startswap function

(define (startSwap heapMod index val2Index) (if (eq? index 1)
							(cons val2Index (cdr heapMod))
							(cons (car heapMod) (startSwap (cdr heapMod) (- index 1) val2Index) )
						))
;-----------------------------------------END OF SWAPPING ALGORITHM-----------------------------------------

;--------------------------MAKE THE HEAP FROM THE LIST (STATUS : SUCCESSFUL) ----------------------------
;(heapify '(6 5 3 1 8 7 2 4) 8)
;heapify function calls a loop to iterate while loop
(define (heapify heap count) (heapifyLoop heap count (parentIndex count)))

;heap while loop

(define (heapifyLoop heap endIndex startIndex) (if 	(>= startIndex 1) 
							(heapifyLoop (siftdown heap startIndex endIndex) endIndex (- startIndex 1))
							heap
						))

;-----------------------------------END OF MAKING THE HEAP----------------------------------------------


;repairs a broken heap
;(siftdown '(1 6 7 4 5 3 2) 1 7)
;-------------------------------REPAIRING A BROKEN HEAP (STATUS : SUCCESSFUL) ----------------------------------
(define (siftdown heap startIndex endIndex)  (siftLoop heap startIndex startIndex (leftChildIndex startIndex) endIndex))

(define (siftLoop heap rootIndex swapIndex child endIndex) (if (< child endIndex) (cond  ((< (getVal heap swapIndex) (getVal heap child))
								(siftLoop heap rootIndex child child endIndex));(set! swapIndex child)
							( (and (<= (+ child 1) endIndex) (< (getVal heap swapIndex) (getVal heap (+ child 1) ) ))
								(siftLoop heap rootIndex (+ child 1) child endIndex));(set! swapIndex (+ child 1))
							
							( (eq? swapIndex rootIndex)
							heap)
							( #t (siftLoop (swap heap heap rootIndex swapIndex) swapIndex swapIndex (leftChildIndex swapIndex) endIndex)))
								
								 heap))	
;---------------------------------------END OF REPAIRING A BROKEN HEAP ------------------------------------------



;-------------------------GETTING VALUE AT AN INDEX IN A LIST (STATUS : SUCCESSFULL) -----------------------------
;need to develop a function getVal to get the value in a list at a point

(define (getVal heap index) (if (eq? index 1) (car heap) (getVal (cdr heap) (- index 1))))

;----------------------------------------END OF GETTING THE VALUE AT AN INDEX-------------------------------------
;calculating the parent index of a heap

(define (parentIndex i) (floor (/ (- i 1) 2)))

(define (leftChildIndex i) (+ (* 2 i) 0))
(define (rightChildIndex i) (+ (* 2 i) 1))