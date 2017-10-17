/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:15:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/17 11:39:38 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern size_t	page_tot;
extern void		*stack;

void		get_size(size_t page_s, size_t size, size_t (*malloc_size)[2])
{
	int		i;
	int		nb_alloc;
	int		j;

	nb_alloc = 100;
	(*malloc_size)[0] = TINY * nb_alloc;
	(*malloc_size)[1] = SMALL * nb_alloc;
	i = -1;
	j = 0;
	while (++i < 3)
		while ((((*malloc_size)[i]) = ((((*malloc_size)[i]) / (nb_alloc + j)) *
				(nb_alloc + j + 1))) % page_s != 0)
			j++;
}

int			check_space(size_t size)
{
	t_mall	*tmp;

	tmp = (t_mall*)stack;
	if (size <= TINY)
		tmp = (t_mall *)stack;
	else if (size <= SMALL)
		tmp = (t_mall *)stack + (sizeof(t_mall) * TINY);
	while (tmp && tmp->use != 'n')
		tmp = tmp->next;
	if (!tmp)
		return (0);
	else
		return (1);
}

void		*malloc(size_t size)
{
	size_t	page_size;
	size_t	malloc_size[2];

	if (!stack)
	{
		page_size = getpagesize();
		get_size(page_size, size, &malloc_size);
		printf("%d\n", page_size);
		if (!init_stack(page_size) || !init_mem(malloc_size, page_size))
			return (NULL);
	}
	return (allocate(size, malloc_size));
}

int		main()
{
	char *str;
	char *str2;
	char *str3;
	char *str4;
	char *str5;

	// str2 =
	printf("sizeof = %lu\n",sizeof(t_mall));
	printf("sizeof = %d\n", 4096 / 24);
	printf("sizeof = %lu\n",sizeof(t_mall) * 1740);
	str = (char*)malloc(200);
	t_mall *tmp = (t_mall *)stack;
	int i = 0;
	while (tmp->next)
	{
		tmp = tmp->next;
		i++;
	}
	str2 = (char*)malloc(200);
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
