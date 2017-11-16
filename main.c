#include "malloc.h"
#include <unistd.h>
int main()
{
	char *str;
	int i = 0;
	while (++i < 9999)
		str = malloc(20);
	show_alloc_mem();
	ft_printf("adr = %p", str);
}
