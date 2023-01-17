section .text
extern error

global ft_strlen
ft_strlen:
	xor rcx, rcx
	or rdi, rdi
	jnz	.loop
	jmp .error
.loop:
	cmp	BYTE[rdi + rcx], 0
	je	.exit
	inc	rcx
	jmp	.loop
.exit:
	mov	rax, rcx
	ret
.error:
	mov rax, -1
	ret
