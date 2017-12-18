#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "malloc.h"

int main()
{
	char *str;

	if (!(str = (char*)malloc(sizeof(char) * 100)))
		return (0);if (!(str = (char*)malloc(sizeof(char) * 100)))
			return (0);if (!(str = (char*)malloc(sizeof(char) * 100)))
				return (0);if (!(str = (char*)malloc(sizeof(char) * 100)))
					return (0);
	str = strcpy(str, "salutfdlghkjfdgkjfdh gkjfdh gkjf");
	printf("%s\n", str);
	write(1,"ici\n",4);
	free((void*)str);
	str = NULL;
	printf("%s\n", str);
	show_alloc_mem();
}
