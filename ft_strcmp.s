global ft_strcmp
section .text
ft_strcmp:
	cmp	rdi, 0
	je	.error
	cmp	rsi, 0
	je	.error
	mov	rcx, 0
	jmp	.loop

.loop:
	cmp	BYTE[rsi + rcx], 0
	je	.exit
	mov	r8b, BYTE[rdi + rcx]
	cmp	BYTE[rsi + rcx], r8b
	jne	.exit
	inc	rcx
	jmp	.loop

.exit:
	mov	al, BYTE[rdi + rcx]
	sub al, BYTE[rsi + rcx]
	movsx rax, al
	ret

.error:
	mov	rax, 0
	ret
