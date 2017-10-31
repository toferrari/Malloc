/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:15:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/31 19:06:26 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern size_t	page_tot[3];
extern void		*stack[3];

void		get_size(size_t page_s, size_t size, size_t (*malloc_size)[2])
{
	int		i;
	int		nb_alloc;
	int		j;

	nb_alloc = 100;
	(*malloc_size)[0] = TINY * nb_alloc;
	(*malloc_size)[1] = SMALL * nb_alloc;
	page_tot[2] = page_s;
	i = -1;
	j = 0;
	while (++i < 3)
		while ((((*malloc_size)[i]) = ((((*malloc_size)[i]) / (nb_alloc + j)) *
				(nb_alloc + j + 1))) % page_s != 0)
			j++;
}

void		*malloc(size_t size)
{
	size_t	page_size;
	size_t	malloc_size[2];

	if (!(*stack))
	{

		page_size = getpagesize();
		get_size(page_size, size, &malloc_size);
		if (!init_stack(page_size, malloc_size) || !init_mem(malloc_size, page_size))
			return (NULL);
	}
	return (allocate(size));
}

int		main()
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *str5;

	// str2 =
	printf("sizeof = %d\n", 4096 / 24);
	printf("sizeof = %lu\n",sizeof(t_mall));
	// str = (char*)malloc(2000);
	str2 = (char*)malloc(50);
	// str = (char*)malloc(10000);
	t_mall *tmp;
	t_mall *tmp1;
	tmp1 = (t_mall *)(stack[0]);
	t_mall *tmp2;
	tmp2 = (t_mall *)(stack[1]);
	int i = -1;
	printf("tmp 1 = %p\ntmp 2 = %p\n", tmp1, tmp2);
	// printf("adr str2 = %p\n", str2);
	// printf("adr str3 = %p\n", str3);
	// printf("adr 1er tiny = %p\n", stack[0]);
	// printf("realloc str2 = %p\n", str2);
	str3 = (char*)malloc(200);
	str3 = (char*)malloc(2000);
	// str4 = (char*)malloc(2000);
	while (++i < 3)
	{
		int j = 0;
		tmp = (t_mall *)(stack[i]);
		while (tmp)
		{
			if (tmp->use == 'y')
			// if (j == 127)
				// printf("apres le 128eme elem -> %p\n", tmp->next);
				printf("adr mall = %p, adr ptr = %p len = %zu, use = %c \
count = %d\n", tmp, tmp->ptr, tmp->len, tmp->use, j);
			tmp = tmp->next;
			j++;
		}
		printf("i = %i\n", j);
	}
	printf("adr 1er small = %p\n", stack[1]);
	// printf("page_tot%d\n\n", page_tot);
	// printf("%c -> %p\n", tmp->type, tmp->ptr);
	// tmp = tmp->next;
	// printf("%c -> %p\n", tmp->type, tmp->ptr);
	// tmp = tmp->next;
	// printf("%c -> %p\n", tmp->type, tmp->ptr);
	// str2 = (char*)malloc(2);
	// str22 = (char*)malloc(2);
	// str3 = (char*)malloc(200);
	// str4 = (char*)malloc(220);
	// str5 = (char*)malloc(200);
	// printf("%p -> %p -> %p -> %p -> %p -> %p\n", str, str2, str22,str3, str4, str5);
	// free((void*)str22);
	// printf("%p", str228);
	// str22[0] = 'f';
	return 0;
}
