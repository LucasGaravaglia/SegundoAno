	.file	"sep20aula.c"
	.intel_syntax noprefix
	.text
	.comm	v,400,32
	.comm	n,4,4
	.section	.rodata
.LC0:
	.string	"Digite 5 numeros:"
.LC1:
	.string	"%d"
	.text
	.globl	ler
	.type	ler, @function
ler:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	sub	esp, 12
	push	OFFSET FLAT:.LC0
	call	puts
	add	esp, 16
	mov	DWORD PTR [ebp-12], 0
	jmp	.L2
.L3:
	mov	eax, DWORD PTR [ebp-12]
	sal	eax, 2
	add	eax, OFFSET FLAT:v
	sub	esp, 8
	push	eax
	push	OFFSET FLAT:.LC1
	call	__isoc99_scanf
	add	esp, 16
	add	DWORD PTR [ebp-12], 1
.L2:
	cmp	DWORD PTR [ebp-12], 4
	jle	.L3
	mov	eax, 5
	leave
	ret
	.size	ler, .-ler
	.globl	produto
	.type	produto, @function
produto:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	eax, DWORD PTR [ebp+12]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	DWORD PTR [ebp-4], eax
	mov	DWORD PTR [ebp-8], 1
	jmp	.L6
.L7:
	mov	eax, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [eax]
	mov	edx, DWORD PTR [ebp-8]
	imul	eax, edx
	mov	DWORD PTR [ebp-8], eax
	add	DWORD PTR [ebp+8], 4
.L6:
	mov	eax, DWORD PTR [ebp+8]
	cmp	eax, DWORD PTR [ebp-4]
	jb	.L7
	nop
	leave
	ret
	.size	produto, .-produto
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
	call	ler
	mov	eax, DWORD PTR n
	sub	esp, 8
	push	eax
	push	OFFSET FLAT:v
	call	produto
	add	esp, 16
	sub	esp, 8
	push	eax
	push	OFFSET FLAT:.LC1
	call	printf
	add	esp, 16
	mov	eax, 0
	mov	ecx, DWORD PTR [ebp-4]
	leave
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
