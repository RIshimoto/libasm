global ft_strdup
extern ft_strlen
extern ft_strcpy
extern malloc

section .text
ft_strdup:
	xor rcx, rcx
	or	rdi, rdi
	jnz	.loop
	jmp .error
.loop:
    push    rdi
    call    ft_strlen
    mov     rdi, rax
    call    malloc
    mov     rdi, rax
    pop     rsi
	call	ft_strcpy
    ret
.error:
	mov	rax, 0 
	ret
