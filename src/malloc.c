/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:15:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/12/18 18:47:34 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern size_t	g_page_tot[3];
extern void		*g_stack[3];

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

void		*malloc(size_t size)
{
	size_t	page_size;
	size_t	malloc_size[2];
	ft_putnbr(size);
	ft_putchar('\n');
	// ft_putnbr(size);
	// ft_putendl("");
	page_size = getpagesize();
	get_size(page_size, size, &malloc_size);
	if (!(*g_stack))
	{
		if (!init_stack(page_size, malloc_size) ||
		!init_mem(malloc_size, page_size))
			return (NULL);
	}
	else if (!check_place(size) && !new_page(size, malloc_size, page_size))
		return (NULL);
	return (allocate(size));
}
