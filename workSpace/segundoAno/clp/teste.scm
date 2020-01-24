
;-----------------fatorial-------------------
;(define (fatorial m)
;(if(= m 0)
;1
;(* m (fatorial(- m 1)))
;)
;)
;(fatorial 5)
;----------------------calculo area quadrado---------------------
; (define (quadrado numero)
; (* numero numero)
; )
; (quadrado 5)
(define (numero atm list1)
	(cond
		( (null? list1) #F)
		( (eq? atm (car list1)) #T)
		( else (numero atm (cdr list1)))
	)
)
(numero 'A '(A B C K))
