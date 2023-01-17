SRCS = \
	ft_strlen.s \
	ft_strcpy.s \
	ft_strcmp.s \
	ft_write.s \
	ft_read.s \
	ft_strdup.s 
#BONUS=
OBJS = $(SRCS:.s=.o)
#BNSOBJS = $(BONUS:.s=.o)
NAME = libasm.a
AS = nasm
ASFLAGS = -felf64
CC = gcc 
CFLAGS = -Wall -Wextra -Werror
.SUFFIXES: .o .s

ifdef BONUS_FLAG
	MATERIALS = $(OBJS) $(BNSOBJS)
else
	MATERIALS = $(OBJS)
endif

$(NAME): $(OBJS)
	$(AR) rc $@ $^
	
all: main.o $(NAME)
	$(CC) -no-pie -o libasm -L. $< -lasm

main.o: main.c
	gcc -c $<

clean:
	@rm -f *.o

fclean: clean
	@$(RM) -f $(NAME) libasm

re: fclean all

.s.o:
	$(AS) $(ASFLAGS) $<

bonus:
	$(MAKE) BONUS_FLAG=1 all

.PHONY: all re clean fclean bonus re .s.o
