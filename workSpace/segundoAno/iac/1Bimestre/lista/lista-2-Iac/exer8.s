	.file	"exer8.c"
	.intel_syntax noprefix
	.text
	.globl	shiftmaior
	.type	shiftmaior, @function
shiftmaior:
	push	ebp
	mov	ebp, esp
#APP
# 18 "exer8.c" 1
	.intel_syntax noprefix 
    mov esi,[ebp+8]             
    mov ecx,[ebp+12]            
1:  cmp ecx,[ebp+16]            
    jge 3                       
    mov eax,[esi]               
    cmp eax, [esi+4]            
    jle 2                       
    xchg eax,[esi+4]            
    xchg eax,[esi]              
2:  inc ecx                     
    lea esi,[esi+4]             
    jmp 1                       
3:                              
    .att_syntax prefix
# 0 "" 2
#NO_APP
	nop
	pop	ebp
	ret
	.size	shiftmaior, .-shiftmaior
	.globl	ordenar
	.type	ordenar, @function
ordenar:
	push	ebp
	mov	ebp, esp
#APP
# 42 "exer8.c" 1
	.intel_syntax noprefix 
    mov ecx [ebp+12]            
    dec ecx                     
.L5: jeccxz 20                  
    push ecx                    
    sub esp, 12                 
    mov [esp+8],ecx             
    mov DWORD PTR [esp+4],0     
    mov eax,[ebp+8]             
    mov [esp],eax               
    call shiftmaior             
    add esp,12                  
    pop ecx                     
    dec ecx                     
    jmp .L5                     
20:                             
    .att_syntax prefix
# 0 "" 2
#NO_APP
	nop
	pop	ebp
	ret
	.size	ordenar, .-ordenar
	.section	.rodata
.LC0:
	.string	"#%d = %d\n"
	.text
	.globl	show
	.type	show, @function
show:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	DWORD PTR [ebp-12], 0
	jmp	.L4
.L5:
	mov	eax, DWORD PTR [ebp-12]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	sub	esp, 4
	push	eax
	push	DWORD PTR [ebp-12]
	push	OFFSET FLAT:.LC0
	call	printf
	add	esp, 16
	add	DWORD PTR [ebp-12], 1
.L4:
	mov	eax, DWORD PTR [ebp-12]
	cmp	eax, DWORD PTR [ebp+12]
	jl	.L5
	nop
	nop
	leave
	ret
	.size	show, .-show
	.globl	v
	.data
	.align 32
	.type	v, @object
	.size	v, 40
v:
	.long	10
	.long	9
	.long	8
	.long	7
	.long	6
	.long	1
	.long	2
	.long	3
	.long	4
	.long	5
	.globl	n
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.long	10
	.text
	.globl	main
	.type	main, @function
main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
	sub	esp, 4
#APP
# 69 "exer8.c" 1
	.intel_syntax noprefix     
        sub esp, 8                  
        mov eax, n                  
        mov [esp+4],eax             
        mov eax, OFFSET v           
        mov [esp], eax              
        call ordenar                
        add esp, 8                  
    .att_syntax prefix
# 0 "" 2
#NO_APP
	mov	eax, DWORD PTR n
	sub	esp, 8
	push	eax
	push	OFFSET FLAT:v
	call	show
	add	esp, 16
	mov	eax, 0
	mov	ecx, DWORD PTR [ebp-4]
	leave
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
