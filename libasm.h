#ifndef LIBASM_H
# define LIBASM_H

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

# define HB			"\x1b[1m"	// HighBright
# define UL			"\x1b[4m"	// UnderLine
# define RED		"\x1b[31m"	// Red
# define GREEN		"\x1b[32m"	// Green
# define RESET		"\x1b[0m"	// Reset

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *s);
char				*ft_strcpy(char *s, const char *t);
int					ft_strcmp(const char *s, const char *t);
ssize_t				ft_write(int fd, const void *buf, size_t count);
ssize_t				ft_read(int fd, void *buf, size_t count);
char				*ft_strdup(const char *s);
void				mandatory_test(void);
void				bonus_test(void);

#endif
