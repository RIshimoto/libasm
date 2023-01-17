global ft_write
; ft_write(int fd, void *buf, size_t count);
extern __errno_location

section .text
ft_write:
	mov rax, 1
	syscall

	cmp rax, 0
	jl .error
	ret

.error:
	neg rax
	push rax
	call __errno_location
	pop qword [rax]
	mov rax, -1	
	ret
