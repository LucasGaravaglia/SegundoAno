 	.file	"main.c"
	.intel_syntax noprefix
	.text
	.comm	a32,4,4
	.comm	b32,4,4
	.comm	a8,1,1
	.globl	main
	.type	main, @function
main:
	push	ebp
	mov	ebp, esp
	movzx	eax, BYTE PTR a8
	movsx	edx, al
	mov	eax, DWORD PTR b32
	add	eax, edx
	mov	DWORD PTR a32, eax
	mov	eax, 0
	pop	ebp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
