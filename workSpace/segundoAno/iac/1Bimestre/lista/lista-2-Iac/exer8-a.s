	.file	"main.c"
	.intel_syntax noprefix
	.text
	.globl	ordenar
	.type	ordenar, @function
ordenar:
	push	ebp
	mov	ebp, esp
	sub	esp, 32
	mov	DWORD PTR [ebp-12], 0
	jmp	.L2
.L6:
	mov	eax, DWORD PTR [ebp-12]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [ebp-20], eax
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [ebp-16], eax
	mov	eax, DWORD PTR [ebp-12]
	add	eax, 1
	mov	DWORD PTR [ebp-8], eax
	jmp	.L3
.L5:
	mov	eax, DWORD PTR [ebp-8]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	cmp	DWORD PTR [ebp-20], eax
	jge	.L4
	mov	eax, DWORD PTR [ebp-8]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [ebp-20], eax
	mov	eax, DWORD PTR [ebp-8]
	mov	DWORD PTR [ebp-16], eax
.L4:
	add	DWORD PTR [ebp-8], 1
.L3:
	mov	eax, DWORD PTR [ebp-8]
	cmp	eax, DWORD PTR [ebp+12]
	jl	.L5
	mov	eax, DWORD PTR [ebp-12]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [ebp-4], eax
	mov	eax, DWORD PTR [ebp-16]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	edx, DWORD PTR [ebp-12]
	lea	ecx, [0+edx*4]
	mov	edx, DWORD PTR [ebp+8]
	add	edx, ecx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ebp-8]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	edx, eax
	mov	eax, DWORD PTR [ebp-4]
	mov	DWORD PTR [edx], eax
	add	DWORD PTR [ebp-12], 1
.L2:
	mov	eax, DWORD PTR [ebp-12]
	cmp	eax, DWORD PTR [ebp+12]
	jl	.L6
	nop
	nop
	leave
	ret
	.size	ordenar, .-ordenar
	.globl	shiftmaior
	.type	shiftmaior, @function
shiftmaior:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	eax, DWORD PTR [ebp+12]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [ebp-4], eax
	jmp	.L8
.L10:
	mov	eax, DWORD PTR [ebp-4]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	cmp	DWORD PTR [ebp-12], eax
	jge	.L9
	mov	eax, DWORD PTR [ebp-4]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-4]
	mov	DWORD PTR [ebp-8], eax
.L9:
	add	DWORD PTR [ebp-4], 1
.L8:
	mov	eax, DWORD PTR [ebp-4]
	cmp	eax, DWORD PTR [ebp+16]
	jl	.L10
	mov	eax, DWORD PTR [ebp-8]
	mov	DWORD PTR [ebp-4], eax
	jmp	.L11
.L12:
	mov	eax, DWORD PTR [ebp-4]
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-4]
	add	eax, 1
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	eax, edx
	mov	edx, DWORD PTR [ebp-4]
	lea	ecx, [0+edx*4]
	mov	edx, DWORD PTR [ebp+8]
	add	edx, ecx
	mov	eax, DWORD PTR [eax]
	mov	DWORD PTR [edx], eax
	mov	eax, DWORD PTR [ebp-4]
	add	eax, 1
	lea	edx, [0+eax*4]
	mov	eax, DWORD PTR [ebp+8]
	add	edx, eax
	mov	eax, DWORD PTR [ebp-12]
	mov	DWORD PTR [edx], eax
	add	DWORD PTR [ebp-4], 1
.L11:
	mov	eax, DWORD PTR [ebp-4]
	cmp	eax, DWORD PTR [ebp+16]
	jl	.L12
	nop
	nop
	leave
	ret
	.size	shiftmaior, .-shiftmaior
	.globl	main
	.type	main, @function
main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
	sub	esp, 420
	mov	eax, DWORD PTR gs:20
	mov	DWORD PTR [ebp-12], eax
	xor	eax, eax
	push	DWORD PTR [ebp-416]
	lea	eax, [ebp-412]
	push	eax
	call	ordenar
	add	esp, 8
	push	40
	push	12
	lea	eax, [ebp-412]
	push	eax
	call	shiftmaior
	add	esp, 12
	mov	eax, 0
	mov	edx, DWORD PTR [ebp-12]
	xor	edx, DWORD PTR gs:20
	je	.L15
	call	__stack_chk_fail
.L15:
	mov	ecx, DWORD PTR [ebp-4]
	leave
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
