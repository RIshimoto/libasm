#include "libasm.h"

void test_ft_atoi_base(void)
{
	const char *name = "ft_atoi_base";
	printf("=====%*s%*s=====\n", 16, name, 4, "");
}

void test_ft_list_push_front(void)
{
	const char *name = "ft_list_push_front";
	printf("=====%*s%*s=====\n", 19, name, 1, "");
}
void test_ft_list_size(void)
{
	const char *name = "ft_list_size";
	printf("=====%*s%*s=====\n", 16, name, 4, "");
}
void test_ft_list_sort(void)
{
	const char *name = "ft_list_sort";
	printf("=====%*s%*s=====\n", 16, name, 4, "");
}
void test_ft_list_remove_if(void)
{
	const char *name = "ft_list_remove_if";
	printf("=====%*s%*s=====\n", 18, name, 2, "");
}

void bonus_test(void)
{
	test_ft_atoi_base(void);
	test_ft_list_push_front(void);
	test_ft_list_size(void);
	test_ft_list_sort(void);
	test_ft_list_remove_if(void);
}


int main(int argc, char **argv)
{
	mandatory_test();
	bonus_test();
	return 0;
}
