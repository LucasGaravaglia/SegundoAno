	.file	"main.c"
	.intel_syntax noprefix
	.text
	.section	.rodata
.LC0:
	.string	"clear"
.LC1:
	.string	"\t\t\tSNAKE GAME\n"
	.align 4
.LC2:
	.string	"\n\nQuantidade de frutas pegas no total: %d"
.LC3:
	.string	"Voce perdeu.\n"
.LC4:
	.string	"Sua pontuacao foi de : %d\n\n"
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
	sub	esp, 8052
	mov	eax, DWORD PTR gs:20
	mov	DWORD PTR [ebp-12], eax
	xor	eax, eax
	sub	esp, 12
	push	0
	call	time
	add	esp, 16
	sub	esp, 12
	push	eax
	call	srand
	add	esp, 16
	mov	DWORD PTR [ebp-8052], 119
	mov	DWORD PTR [ebp-8048], 119
	mov	DWORD PTR [ebp-8044], -1
	mov	DWORD PTR [ebp-8036], 25
	mov	DWORD PTR [ebp-8032], 15
	call	rand
	mov	ecx, eax
	mov	edx, 1374389535
	mov	eax, ecx
	imul	edx
	sar	edx, 4
	mov	eax, ecx
	sar	eax, 31
	sub	edx, eax
	mov	eax, edx
	imul	eax, eax, 50
	sub	ecx, eax
	mov	eax, ecx
	sub	eax, 1
	mov	DWORD PTR [ebp-8020], eax
	call	rand
	mov	ecx, eax
	mov	edx, -2004318071
	mov	eax, ecx
	imul	edx
	lea	eax, [edx+ecx]
	sar	eax, 4
	mov	edx, eax
	mov	eax, ecx
	sar	eax, 31
	sub	edx, eax
	mov	eax, edx
	imul	eax, eax, 30
	sub	ecx, eax
	mov	eax, ecx
	sub	eax, 1
	mov	DWORD PTR [ebp-8016], eax
.L23:
	sub	esp, 12
	push	OFFSET FLAT:.LC0
	call	system
	add	esp, 16
	sub	esp, 12
	push	OFFSET FLAT:.LC1
	call	puts
	add	esp, 16
	mov	edx, DWORD PTR [ebp-8020]
	mov	eax, DWORD PTR [ebp-8036]
	cmp	edx, eax
	jne	.L2
	mov	edx, DWORD PTR [ebp-8016]
	mov	eax, DWORD PTR [ebp-8032]
	cmp	edx, eax
	jne	.L2
	call	rand
	mov	ecx, eax
	mov	edx, 1374389535
	mov	eax, ecx
	imul	edx
	sar	edx, 4
	mov	eax, ecx
	sar	eax, 31
	sub	edx, eax
	mov	eax, edx
	imul	eax, eax, 50
	sub	ecx, eax
	mov	eax, ecx
	sub	eax, 2
	mov	DWORD PTR [ebp-8020], eax
	call	rand
	mov	ecx, eax
	mov	edx, -2004318071
	mov	eax, ecx
	imul	edx
	lea	eax, [edx+ecx]
	sar	eax, 4
	mov	edx, eax
	mov	eax, ecx
	sar	eax, 31
	sub	edx, eax
	mov	eax, edx
	imul	eax, eax, 30
	sub	ecx, eax
	mov	eax, ecx
	sub	eax, 2
	mov	DWORD PTR [ebp-8016], eax
	add	DWORD PTR [ebp-8044], 1
.L2:
	sub	esp, 12
	push	DWORD PTR [ebp-8044]
	lea	eax, [ebp-8012]
	push	eax
	lea	eax, [ebp-8020]
	push	eax
	lea	eax, [ebp-8036]
	push	eax
	push	DWORD PTR [ebp-8052]
	call	mostracampo
	add	esp, 32
	mov	eax, DWORD PTR [ebp-8044]
	add	eax, 1
	sub	esp, 8
	push	eax
	push	OFFSET FLAT:.LC2
	call	printf
	add	esp, 16
	sub	esp, 12
	push	100000
	call	usleep
	add	esp, 16
	call	kbhit
	test	eax, eax
	je	.L3
	call	getchch
	mov	DWORD PTR [ebp-8052], eax
.L3:
	mov	eax, DWORD PTR stdin
	sub	esp, 8
	push	0
	push	eax
	call	setbuf
	add	esp, 16
	cmp	DWORD PTR [ebp-8052], 119
	je	.L4
	cmp	DWORD PTR [ebp-8052], 115
	je	.L4
	cmp	DWORD PTR [ebp-8052], 100
	je	.L4
	cmp	DWORD PTR [ebp-8052], 97
	jne	.L5
.L4:
	mov	eax, DWORD PTR [ebp-8052]
	mov	DWORD PTR [ebp-8048], eax
	jmp	.L6
.L5:
	mov	eax, DWORD PTR [ebp-8048]
	mov	DWORD PTR [ebp-8052], eax
.L6:
	mov	eax, DWORD PTR [ebp-8032]
	cmp	eax, 29
	je	.L26
	mov	eax, DWORD PTR [ebp-8036]
	cmp	eax, 49
	je	.L27
	mov	eax, DWORD PTR [ebp-8032]
	test	eax, eax
	je	.L28
	mov	eax, DWORD PTR [ebp-8036]
	test	eax, eax
	je	.L29
	sub	esp, 8
	push	DWORD PTR [ebp-8044]
	lea	eax, [ebp-8012]
	push	eax
	call	conferecorpo
	add	esp, 16
	test	eax, eax
	jne	.L30
	mov	eax, DWORD PTR [ebp-8036]
	mov	DWORD PTR [ebp-8028], eax
	mov	eax, DWORD PTR [ebp-8032]
	mov	DWORD PTR [ebp-8024], eax
	cmp	DWORD PTR [ebp-8052], 119
	jne	.L13
	mov	eax, DWORD PTR [ebp-8032]
	sub	eax, 1
	mov	DWORD PTR [ebp-8032], eax
	jmp	.L14
.L13:
	cmp	DWORD PTR [ebp-8052], 115
	jne	.L15
	mov	eax, DWORD PTR [ebp-8032]
	add	eax, 1
	mov	DWORD PTR [ebp-8032], eax
	jmp	.L14
.L15:
	cmp	DWORD PTR [ebp-8052], 100
	jne	.L16
	mov	eax, DWORD PTR [ebp-8036]
	add	eax, 1
	mov	DWORD PTR [ebp-8036], eax
	jmp	.L14
.L16:
	cmp	DWORD PTR [ebp-8052], 97
	jne	.L14
	mov	eax, DWORD PTR [ebp-8036]
	sub	eax, 1
	mov	DWORD PTR [ebp-8036], eax
.L14:
	cmp	DWORD PTR [ebp-8044], -1
	je	.L31
	cmp	DWORD PTR [ebp-8044], 0
	jne	.L19
	mov	edx, DWORD PTR [ebp-8028]
	mov	eax, DWORD PTR [ebp-8044]
	mov	DWORD PTR [ebp-8012+eax*4], edx
	mov	eax, DWORD PTR [ebp-8024]
	mov	edx, DWORD PTR [ebp-8044]
	add	edx, 1000
	mov	DWORD PTR [ebp-8012+edx*4], eax
.L19:
	mov	eax, DWORD PTR [ebp-8044]
	mov	DWORD PTR [ebp-8040], eax
	jmp	.L21
.L22:
	mov	eax, DWORD PTR [ebp-8040]
	sub	eax, 1
	mov	edx, DWORD PTR [ebp-8012+eax*4]
	mov	eax, DWORD PTR [ebp-8040]
	mov	DWORD PTR [ebp-8012+eax*4], edx
	mov	eax, DWORD PTR [ebp-8040]
	sub	eax, 1
	add	eax, 1000
	mov	eax, DWORD PTR [ebp-8012+eax*4]
	mov	edx, DWORD PTR [ebp-8040]
	add	edx, 1000
	mov	DWORD PTR [ebp-8012+edx*4], eax
	sub	DWORD PTR [ebp-8040], 1
.L21:
	cmp	DWORD PTR [ebp-8040], 0
	jg	.L22
	mov	eax, DWORD PTR [ebp-8028]
	mov	DWORD PTR [ebp-8012], eax
	mov	eax, DWORD PTR [ebp-8024]
	mov	DWORD PTR [ebp-4012], eax
	jmp	.L23
.L31:
	nop
	jmp	.L23
.L26:
	nop
	jmp	.L8
.L27:
	nop
	jmp	.L8
.L28:
	nop
	jmp	.L8
.L29:
	nop
	jmp	.L8
.L30:
	nop
.L8:
	sub	esp, 12
	push	OFFSET FLAT:.LC0
	call	system
	add	esp, 16
	sub	esp, 12
	push	OFFSET FLAT:.LC3
	call	puts
	add	esp, 16
	mov	eax, DWORD PTR [ebp-8044]
	add	eax, 1
	sub	esp, 8
	push	eax
	push	OFFSET FLAT:.LC4
	call	printf
	add	esp, 16
	call	getchar
	mov	eax, 0
	mov	ecx, DWORD PTR [ebp-12]
	xor	ecx, DWORD PTR gs:20
	je	.L25
	call	__stack_chk_fail
.L25:
	mov	ecx, DWORD PTR [ebp-4]
	leave
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 9.1.0"
	.section	.note.GNU-stack,"",@progbits
