	.file	"exer9.c"
	.intel_syntax noprefix
	.text
	.globl	f
	.type	f, @function
f:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	eax, DWORD PTR [ebp+12]
	mov	DWORD PTR [ebp-16], eax
	mov	eax, DWORD PTR [ebp+16]
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp+20]
	mov	DWORD PTR [ebp-8], eax
	mov	eax, DWORD PTR [ebp+24]
	mov	DWORD PTR [ebp-4], eax
	mov	eax, DWORD PTR [ebp-16]
	add	eax, 1
	mov	DWORD PTR [ebp-16], eax
	mov	eax, DWORD PTR [ebp-12]
	add	eax, 1
	mov	DWORD PTR [ebp-12], eax
	mov	eax, DWORD PTR [ebp-8]
	add	eax, 1
	mov	DWORD PTR [ebp-8], eax
	mov	eax, DWORD PTR [ebp-4]
	add	eax, 1
	mov	DWORD PTR [ebp-4], eax
	mov	eax, DWORD PTR [ebp+8]
	mov	edx, DWORD PTR [ebp-16]
	mov	DWORD PTR [eax], edx
	mov	edx, DWORD PTR [ebp-12]
	mov	DWORD PTR [eax+4], edx
	mov	edx, DWORD PTR [ebp-8]
	mov	DWORD PTR [eax+8], edx
	mov	edx, DWORD PTR [ebp-4]
	mov	DWORD PTR [eax+12], edx
	mov	eax, DWORD PTR [ebp+8]
	leave
	ret	4
	.size	f, .-f
	.comm	global,16,4
	.comm	result,16,4
	.globl	main
	.type	main, @function
main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
	sub	esp, 52
	mov	eax, ecx
	mov	eax, DWORD PTR [eax+4]
	mov	DWORD PTR [ebp-28], eax
	mov	eax, DWORD PTR gs:20
	mov	DWORD PTR [ebp-12], eax
	xor	eax, eax
	lea	eax, [ebp-56]
	push	DWORD PTR global+12
	push	DWORD PTR global+8
	push	DWORD PTR global+4
	push	DWORD PTR global
	push	eax
	call	f
	add	esp, 16
	mov	eax, DWORD PTR [ebp-56]
	mov	DWORD PTR result, eax
	mov	eax, DWORD PTR [ebp-52]
	mov	DWORD PTR result+4, eax
	mov	eax, DWORD PTR [ebp-48]
	mov	DWORD PTR result+8, eax
	mov	eax, DWORD PTR [ebp-44]
	mov	DWORD PTR result+12, eax
	mov	eax, 0
	mov	edx, DWORD PTR [ebp-12]
	xor	edx, DWORD PTR gs:20
	je	.L5
	call	__stack_chk_fail
.L5:
	mov	ecx, DWORD PTR [ebp-4]
	leave
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
