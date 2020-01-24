	.file	"dump.c"
	.intel_syntax noprefix
	.text
	.globl	soma
	.type	soma, @function
soma:
	push	ebp
	mov	ebp, esp
	mov	edx, DWORD PTR [ebp+8]
	mov	eax, DWORD PTR [ebp+12]
	add	eax, edx
	pop	ebp
	ret
	.size	soma, .-soma
	.globl	f1
	.type	f1, @function
f1:
	push	ebp
	mov	ebp, esp
	nop
	pop	ebp
	ret
	.size	f1, .-f1
	.globl	f2
	.type	f2, @function
f2:
	push	ebp
	mov	ebp, esp
	nop
	pop	ebp
	ret
	.size	f2, .-f2
	.globl	f3
	.type	f3, @function
f3:
	push	ebp
	mov	ebp, esp
	mov	eax, -1
	pop	ebp
	ret
	.size	f3, .-f3
	.globl	f4
	.type	f4, @function
f4:
	push	ebp
	mov	ebp, esp
	mov	eax, -2
	pop	ebp
	ret
	.size	f4, .-f4
	.globl	lenght
	.type	lenght, @function
lenght:
	push	ebp
	mov	ebp, esp
	sub	esp, 16
	mov	DWORD PTR [ebp-4], 0
	jmp	.L10
.L11:
	add	DWORD PTR [ebp-4], 1
	add	DWORD PTR [ebp+8], 1
.L10:
	mov	eax, DWORD PTR [ebp+8]
	movzx	eax, BYTE PTR [eax]
	test	al, al
	jne	.L11
	mov	eax, DWORD PTR [ebp-4]
	leave
	ret
	.size	lenght, .-lenght
	.globl	fatorial
	.type	fatorial, @function
fatorial:
	push	ebp
	mov	ebp, esp
	sub	esp, 8
	cmp	DWORD PTR [ebp+8], 0
	jle	.L14
	mov	eax, DWORD PTR [ebp+8]
	sub	eax, 1
	sub	esp, 12
	push	eax
	call	fatorial
	add	esp, 16
	imul	eax, DWORD PTR [ebp+8]
	jmp	.L15
.L14:
	mov	eax, 1
.L15:
	leave
	ret
	.size	fatorial, .-fatorial
	.section	.rodata
.LC0:
	.string	"%p: "
.LC1:
	.string	"%02X "
	.text
	.globl	dump
	.type	dump, @function
dump:
	push	ebp
	mov	ebp, esp
	sub	esp, 24
	mov	eax, DWORD PTR [ebp+16]
	add	eax, 1
	mov	DWORD PTR [ebp-12], eax
	jmp	.L17
.L19:
	mov	eax, DWORD PTR [ebp-12]
	cmp	eax, DWORD PTR [ebp+16]
	jle	.L18
	mov	DWORD PTR [ebp-12], 0
	sub	esp, 12
	push	10
	call	putchar
	add	esp, 16
	sub	esp, 8
	push	DWORD PTR [ebp+8]
	push	OFFSET FLAT:.LC0
	call	printf
	add	esp, 16
.L18:
	mov	eax, DWORD PTR [ebp+8]
	movzx	eax, BYTE PTR [eax]
	movzx	eax, al
	sub	esp, 8
	push	eax
	push	OFFSET FLAT:.LC1
	call	printf
	add	esp, 16
	add	DWORD PTR [ebp-12], 1
	add	DWORD PTR [ebp+8], 1
.L17:
	mov	eax, DWORD PTR [ebp+8]
	cmp	eax, DWORD PTR [ebp+12]
	jbe	.L19
	sub	esp, 12
	push	10
	call	putchar
	add	esp, 16
	nop
	leave
	ret
	.size	dump, .-dump
	.globl	z
	.data
	.align 4
	.type	z, @object
	.size	z, 4
z:
	.long	1000
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
	sub	esp, 52
	mov	eax, ecx
	mov	eax, DWORD PTR [eax+4]
	mov	DWORD PTR [ebp-44], eax
	mov	eax, DWORD PTR gs:20
	mov	DWORD PTR [ebp-12], eax
	xor	eax, eax
	mov	DWORD PTR [ebp-21], 1111581281
	mov	DWORD PTR [ebp-17], 169881904
	mov	BYTE PTR [ebp-13], 0
	fld	DWORD PTR .LC2
	fstp	DWORD PTR [ebp-32]
	fld	DWORD PTR [ebp-32]
	fchs
	fstp	DWORD PTR [ebp-28]
	lea	eax, [ebp-21]
	push	eax
	call	lenght
	add	esp, 4
	mov	edx, eax
	lea	eax, [ebp-21]
	add	eax, edx
	sub	esp, 4
	push	10
	push	eax
	lea	eax, [ebp-21]
	push	eax
	call	dump
	add	esp, 16
	mov	eax, 0
	mov	ecx, DWORD PTR [ebp-12]
	xor	ecx, DWORD PTR gs:20
	je	.L22
	call	__stack_chk_fail
.L22:
	mov	ecx, DWORD PTR [ebp-4]
	leave
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.section	.rodata
	.align 4
.LC2:
	.long	3279893299
	.ident	"GCC: (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0"
	.section	.note.GNU-stack,"",@progbits
