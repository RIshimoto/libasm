global ft_strcpy

section .text
ft_strcpy:
	cmp rdi, 0
	je	.error
	cmp rsi, 0
	je	.error
	mov rdx, 0 
	jmp	.loop
.loop:
	cmp	BYTE[rsi + rdx], 0
	je	.exit
	mov	r8b, BYTE[rsi + rdx]
	mov	BYTE[rdi + rdx], r8b
	inc	rdx
	jmp	.loop
.exit:
	mov BYTE[rdi + rdx], 0
	mov	rax, rdi
	ret
.error:
	mov rax, 0
	ret
