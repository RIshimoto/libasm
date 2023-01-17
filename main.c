#include "libasm.h"

bool believe = true;

const char *str[] = {"ABCDEF", "123", "abcd", "$", "",  "\0", NULL};
int fail = 0;
static void	test_ft_strlen(void)
{
	const char *name = "ft_strlen";
	printf("=====%*s%*s=====\n", 15, name, 5, "");
	size_t your_ret;
	size_t origin_ret;

	for (int i = 0; str[i] != NULL ; i++)
	{
		printf("%s%s(\"%s\")%*s%s",
				HB,name,str[i],(int)(30-strlen(str[i])),"",RESET);
		your_ret = ft_strlen(str[i]);	
		origin_ret = strlen(str[i]);	
		if (your_ret == origin_ret)
		{
			printf("%s[OK]%s\n", GREEN, RESET);
			if (!believe)
			{
				printf("your  -> %ld\n", your_ret);
				printf("origin-> %ld\n", origin_ret);
			}	
		}
		else
		{
			fail++;
			printf("%s[FAIL]%s\n", RED, RESET);
			printf("your   -> %ld\n", your_ret);
			printf("origin-> %ld\n", origin_ret);
		}
	}
	// error
	printf("%s%s(NULL)%*s%s", HB, name, 26, "", RESET);
	your_ret = ft_strlen(NULL);
	if (!believe)
		printf("%ld", your_ret);
	printf("\n");
}

static void	test_ft_strcpy(void)
{
	const char *name = "ft_strcpy";
	printf("=====%*s%*s=====\n", 15, name, 5, "");
	char *p, *q, *r, *s;
	char *your_ret;
	char *origin_ret;

	for (int i = 0; str[i] != NULL; i++)
	{
		for (int j = 0; str[j] != NULL ; j++)
		{
			p = strdup(str[i]);
			q = strdup(str[j]);
			r = strdup(str[i]);
			s = strdup(str[j]);
			printf("%s%s(\"%s\", \"%s\")%*s%s", 
					HB,name,p,q,(int)(30-strlen(q)-strlen(p)-4),"",RESET);
			origin_ret = strcpy(p, q);
			your_ret = ft_strcpy(r, s);
			if (strcmp(origin_ret, your_ret) == 0 && strcmp(p, r) == 0)
			{
				printf("%s[OK]%s\n", GREEN, RESET);
				if (!believe)
				{
					printf("%13s%6s%syour%s%6s", "", "", UL, RESET, "");
					printf("%6s%sorigin%s%6s\n", "", UL, RESET, "");
					printf("return value ");
					printf("%*s[%s]%*s",
						(int)((14-strlen(your_ret))/2), "", 
							your_ret, (int)(7-strlen(your_ret)/2), "");
					printf("%*s[%s]\n",
						(int)((14-strlen(origin_ret))/2), "", origin_ret);
					printf("copy result  ");
					printf("%*s[%s]%*s", 
					(int)(14-strlen(r))/2,"",r,(int)(7-strlen(r)/2),"");
					printf("%*s[%s]\n", (int)(14-strlen(p))/2, "", p);
				}
			}
			else
			{
				fail++;
				printf("%s[FAIL]%s\n", RED, RESET);
				printf("%13s%6s%s%s%s%6s", "", "", UL, "your",RESET,"");
				printf("%6s%s%s%s%6s\n", "", UL,"origin",RESET,"");
				printf("return value ");
				printf("%*s[%s]%*s",
					(int)((14-strlen(your_ret))/2), "", 
						your_ret, (int)(7-strlen(your_ret)/2), "");
				printf("%*s[%s]\n",
					(int)((14-strlen(origin_ret))/2), "", origin_ret);
				printf("copy result  ");
				printf("%*s[%s]%*s",
					(int)(14-strlen(r))/2, "",r,(int)(7-strlen(r)/2),"");
				printf("%*s[%s]\n", (int)(14-strlen(p))/2, "", p);
			}
			free(p);
			free(q);
			free(r);
			free(s);
		}
	}
	// error
	printf("%s%s(NULL, \"Hello\")%*s%s", HB, name,17,"", RESET);
	your_ret = ft_strcpy(NULL, "Hello");
	if (!believe)
		printf("%s", your_ret);
	printf("\n");

	printf("%s%s(\"Hello\", NULL)%*s%s", HB, name,17,"", RESET);
	your_ret = ft_strcpy("Hello", NULL);
	if (!believe)
		printf("%s", your_ret);
	printf("\n");
}

static void test_ft_strcmp(void)
{
	const char *name = "ft_strcmp";
	printf("=====%*s%*s=====\n", 15, name, 5, "");
	char *p, *q;
	int	your_ret;
	int	origin_ret;

	for (int i = 0; str[i] != NULL; i++)
	{
		for (int j = 0; str[j] != NULL; j++)
		{
			p = (char*)str[i];
			q = (char*)str[j];
			printf("%s%s(\"%s\", \"%s\")%*s%s", 
				HB,name,p,q,(int)(30-strlen(q)-strlen(p)-4),"",RESET);
			origin_ret = strcmp(p, q);
			your_ret = ft_strcmp(p, q);
			if (origin_ret == your_ret)
			{
				printf("%s[OK]%s\n", GREEN, RESET);
				if (!believe)
				{
					printf("your  : %d\n", your_ret);
					printf("origin: %d\n", origin_ret);
				}
			}
			else
			{
				fail++;
				printf("%s[FAIL]%s\n", RED, RESET);
				printf("your  : %d\n", your_ret);
				printf("origin: %d\n", origin_ret);
			}
		}
	}
	// error
	printf("%s%s(NULL, \"Hello\")%*s%s", HB,name,17,"",RESET); 
	your_ret = ft_strcmp(NULL, "Hello");
	if (!believe)
		printf("%d", your_ret);
	printf("\n");

	printf("%s%s(\"Hello\", NULL)%*s%s", HB,name,17,"",RESET); 
	your_ret = ft_strcmp("Hello", NULL);
	if (!believe)
		printf("%d", your_ret);
	printf("\n");
}

static void test_ft_write(void)
{
	const char *name = "ft_write";
	printf("=====%*s%*s=====\n", 14, name, 6, "");

	ssize_t your_ret;
	ssize_t	origin_ret;
	int fd;
	FILE *stream;
	char form[100];

	/* 
	* fd == 1 || fd == 2 
	*/
	for (int fd = 1; fd <= 2; fd++)
	{
		stream = (fd == 1 ? stdout : stderr);
		for (int i = 0; str[i] != NULL; i++)
		{
			sprintf(form, "%s%s(%d, \"%s\", %ld)%s\n", 
				HB,name,fd,str[i],strlen(str[i]),RESET);
			write(fd, form, strlen(form));
			sprintf(form,"%6s%6s%s%s%s%6s", "","",UL,"your",RESET,"");
			write(fd, form, strlen(form));
			sprintf(form,"%6s%s%s%s%6s\n", "",UL,"origin",RESET,"");
			write(fd, form, strlen(form));
			
			write(fd, "output", 6);
			//  your write
			write(fd, "           ",(14-strlen(str[i]))/2);
			write(fd, "[", 1);
			your_ret = ft_write(1, str[i], strlen(str[i]));
			write(fd, "]           ", 1+8-strlen(str[i])/2);
			write(fd, "           ", (14-strlen(str[i]))/2);
			//  origin write
			write(fd, "[", 1);
			origin_ret = write(1, str[i], strlen(str[i]));
			write(fd, "]\n", 2);

			write(fd, "return", 6);
			// your return
			fprintf(stream, "       ");
			fprintf(stream, "%ld",your_ret);
			fprintf(stream, "        ");
			// origin return
			fprintf(stream, "        ");
			fprintf(stream, "%ld",origin_ret);
			fprintf(stream, "        ");
			if (origin_ret == your_ret)
				printf("%s  [OK]%s\n\n", GREEN, RESET);
			else
				printf("%s[FAIL]%s\n\n", RED, RESET);
			if (your_ret != origin_ret)
				fail++;
		}
	}
	// ft_write(1, NULL, 0)
	sprintf(form, "%s%s(1, \"NULL\", 0)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	sprintf(form,"%6s%6s%s%s%s%6s", "","",UL,"your",RESET,"");
	write(1, form, strlen(form));
	sprintf(form,"%6s%s%s%s%6s\n", "",UL,"origin",RESET,"");
	write(1, form, strlen(form));
	write(1, "return", 6);
	your_ret = ft_write(1, NULL, 0);
	origin_ret = 0;
	fprintf(stream, "       ");
	fprintf(stream, "%ld", your_ret);
	fprintf(stream, "        ");
	fprintf(stream, "        ");
	fprintf(stream, "%ld", origin_ret);
	fprintf(stream, "        ");
	if (origin_ret == your_ret)
		printf("%s  [OK]%s\n\n", GREEN, RESET);
	else
		printf("%s[FAIL]%s\n\n", RED, RESET);
	/* error
	// ft_write(3, Hello, 6)
	sprintf(form, "%s%s(still_opened, \"Hello\", 6)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(3, "Hello\n", 6);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	*/

	/* 
	* 3 <= fd <= 1024
	*/
	fd = open("write_test", O_CREAT | O_RDWR, S_IRWXU);
	for (int i = 0; str[i] != NULL; i++)
	{
		sprintf(form, "%s%s(%d, \"%s\", %ld)%s\n", 
				HB,name,fd,str[i],strlen(str[i]),RESET);
		write(1, form, strlen(form));
		sprintf(form,"%6s%6s%s%s%s%6s", "","",UL,"your",RESET,"");
		write(1, form, strlen(form));
		sprintf(form,"%6s%s%s%s%6s\n", "",UL,"origin",RESET,"");
		write(1, form, strlen(form));

		write(1, "return", 6);
		// your return
		your_ret = ft_write(fd, str[i], strlen(str[i]));
		// origin return
		origin_ret = strlen(str[i]);
		fprintf(stream, "       ");
		fprintf(stream, "%ld", your_ret);
		fprintf(stream, "        ");
		fprintf(stream, "        ");
		fprintf(stream, "%ld", origin_ret);
		fprintf(stream, "        ");
		if (origin_ret == your_ret)
			printf("%s  [OK]%s\n\n", GREEN, RESET);
		else
			printf("%s[FAIL]%s\n\n", RED, RESET);
	}

	/* error */
	/* 
	* fd < 0 || fd > 1024
	*/
	// ft_write(-1, "test", 5)
	sprintf(form, "%s%s(-1, \"test\", 5)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(-1, "test", 5);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	// ft_write(-1, "tt", 2)
	sprintf(form, "%s%s(-1, \"tt\", 2)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(-1, "tt", 2);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	// ft_write(-1, "Hello", 6)
	sprintf(form, "%s%s(-1, \"Hello\", 6)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(-1, "Hello\n", 6);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	// ft_write(1025, Hello, 6)
	sprintf(form, "%s%s(1025, \"Hello\", 6)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(1025, "Hello\n", 6);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);

	/* error */
	/* 
	* buffer == 0 
	*/
	// ft_write(1, NULL, 4)
	fd = open("main.c", O_CREAT | O_RDWR, S_IRWXU);
	sprintf(form, "%s%s(%d, \"%s\", %d)%*s%s\n", 
				HB,"ft_write",1,"NULL",4,26,"",RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(1, NULL, 4);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	close(fd);

	/* error */
	/* 
	* count < 0
	*/
	// ft_write(1, Hello, -1)
	sprintf(form, "%s%s(1, \"Hello\", -1)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(1, "Hello\n", -1);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);

	/*
	// ft_write(1, Hello, 100000)
	sprintf(form, "%s%s(1, \"Hello\", 100000)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(1, "Hello\n", 1000000);
	printf("%ld\n", your_ret);
	*//*
	// ft_write(1, Hello, 100000000)
	sprintf(form, "%s%s(1, \"Hello\", 100000000000)%s\n",HB,name,RESET);
	write(1, form, strlen(form));
	your_ret = ft_write(1, "Hello", 10000000000);
	printf("%ld\n", your_ret);
	*/
	close(fd);
}	

static void test_ft_read(void)
{
	const char *name = "ft_read";
	printf("=====%*s%*s=====\n", 13, name, 7, "");
	int		fd;
	char	origin[100];
	char	your[100];
	char	form[100];
	ssize_t	origin_ret;
	ssize_t	your_ret;

	/*
	*	fd = 0
	*/
	sprintf(form, "%s%s(%d, \"%s\", %d)%*s%s\n", 
				HB,"ft_read",0,"buffer",10,20,"",RESET);
	write(1, form, strlen(form));
	origin_ret = read(0, origin, 10);
	your_ret = ft_read(0, your, 10);
	if (origin_ret == your_ret && strcmp(your, origin) == 0)
		printf("%s  [OK]%s\n", GREEN, RESET);
	else
		printf("%s[FAIL]%s\n", RED, RESET);
	printf("%18s%syour%s%6s", "", UL, RESET, "");
	printf("%6s%sorigin%s%6s\n", "", UL, RESET, "");
	printf("read result ");
	printf("%*s[%s]%*s",
		(int)((14-strlen(your))/2),"",your,(int)(7-strlen(your)/2),"");
	printf("%*s[%s]\n",
		(int)((14-strlen(origin))/2), "", origin);
	printf("return value ");
	printf("%*s%ld%*s", 6, "", your_ret, 7, "");
	printf("%*s%ld%*s\n", 6, "", origin_ret, 7, "");

	/*
	*	fd >= 3
	*/
	fd = open("read_test.c", O_CREAT | O_RDWR, S_IRWXU);
	your_ret = ft_read(fd, your, 10);
	close(fd);
	fd = open("read_test.c", O_CREAT | O_RDWR, S_IRWXU);
	origin_ret = read(fd, origin, 10);
	close(fd);
	your[your_ret] = '\0';
	origin[origin_ret] = '\0';
	sprintf(form, "%s%s(%d, \"%s\", %d)%*s%s", 
				HB,"ft_read",fd,"buffer",6,24,"",RESET);
	write(1, form, strlen(form));
	if (origin_ret == your_ret && strcmp(your, origin) == 0)
		printf("%s  [OK]%s\n", GREEN, RESET);
	else
		printf("%s[FAIL]%s\n", RED, RESET);
	printf("%18s%syour%s%6s", "", UL, RESET, "");
	printf("%6s%sorigin%s%6s\n", "", UL, RESET, "");
	printf("read result ");
	printf("%*s[%s]%*s",
		(int)((14-strlen(your))/2),"",your,(int)(7-strlen(your)/2),"");
	printf("%*s[%s]\n",
		(int)((14-strlen(origin))/2), "", origin);
	printf("return value ");
	printf("%*s%ld%*s", 6, "", your_ret, 7, "");
	printf("%*s%ld%*s\n", 6, "", origin_ret, 7, "");

	fd = open("main.c", O_CREAT | O_RDWR, S_IRWXU);
	your_ret = ft_read(fd, your, 10);
	close(fd);
	fd = open("main.c", O_CREAT | O_RDWR, S_IRWXU);
	origin_ret = read(fd, origin, 10);
	close(fd);
	your[your_ret] = '\0';
	origin[origin_ret] = '\0';
	sprintf(form, "%s%s(%d, \"%s\", %d)%*s%s", 
				HB,"ft_read",fd,"buffer",6,24,"",RESET);
	write(1, form, strlen(form));
	if (origin_ret == your_ret && strcmp(your, origin) == 0)
		printf("%s  [OK]%s\n", GREEN, RESET);
	else
		printf("%s[FAIL]%s\n", RED, RESET);
	printf("%18s%syour%s%6s", "", UL, RESET, "");
	printf("%6s%sorigin%s%6s\n", "", UL, RESET, "");
	printf("read result ");
	printf("%*s[%s]%*s",
		(int)((14-strlen(your))/2),"",your,(int)(7-strlen(your)/2),"");
	printf("%*s[%s]\n",
		(int)((14-strlen(origin))/2), "", origin);
	printf("return value ");
	printf("%*s%ld%*s", 6, "", your_ret, 7, "");
	printf("%*s%ld%*s\n", 6, "", origin_ret, 7, "");

	/* error */
	/* 
	* fd < 0 || fd > 1024
	*/
	// ft_read(-1, buffer, 6)
	fd = open("main.c", O_CREAT | O_RDWR, S_IRWXU);
	sprintf(form, "%s%s(%d, \"%s\", %d)%*s%s\n", 
				HB,"ft_read",-1,"buffer",6,24,"",RESET);
	write(1, form, strlen(form));
	your_ret = ft_read(-1, your, 10);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	close(fd);
	// ft_read(1025, buffer, 6)
	fd = open("main.c", O_CREAT | O_RDWR, S_IRWXU);
	sprintf(form, "%s%s(%d, \"%s\", %d)%*s%s\n", 
				HB,"ft_read",1025,"buffer",6,24,"",RESET);
	write(1, form, strlen(form));
	your_ret = ft_read(1025, your, 10);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	close(fd);


	/* error */
	/* 
	* count < 0
	*/
	// ft_read(1, buffer, -1)
	fd = open("main.c", O_CREAT | O_RDWR, S_IRWXU);
	sprintf(form, "%s%s(%d, \"%s\", %d)%*s%s\n", 
				HB,"ft_read",1025,"buffer",-1,24,"",RESET);
	write(1, form, strlen(form));
	your_ret = ft_read(1, your, -1);
	printf("%ld\n", your_ret);
	perror("Error");
	write(1, "\n", 1);
	close(fd);

}

static void test_ft_strdup(void)
{
	const char *name = "ft_strdup";
	printf("=====%*s%*s=====\n", 15, name, 5, "");
	char *your;
	char *origin;


	for (int i = 0; str[i] != NULL ; i++)
	{
		printf("%s%s(\"%s\")%*s%s",
				HB,name,str[i],(int)(30-strlen(str[i])),"",RESET);
		your = ft_strdup(str[i]);
		origin = strdup(str[i]);
		if (strcmp(your, origin) == 0)
		{
			printf("%s[OK]%s\n", GREEN, RESET);
			if (!believe)
			{
				printf("your  -> %s\n", your);
				printf("origin-> %s\n", origin);
			}	
		}
		else
		{
			fail++;
			printf("%s[FAIL]%s\n", RED, RESET);
			printf("your  -> %s\n", your);
			printf("origin-> %s\n", origin);
		}
	}
	/* error */
}

void mandatory_test(void)
{
	puts("========== Mandatory =========");
	//test_ft_strlen();
	//test_ft_strcpy();
	//test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	//test_ft_strdup();
	puts("==============================");
}

int main(int argc, char **argv)
{
	mandatory_test();
	if (fail > 0)
		printf("Your code has something fail\n"); 
	return(0);
}
