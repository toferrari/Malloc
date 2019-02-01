/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:15:56 by tferrari          #+#    #+#             */
/*   Updated: 2019/02/01 13:00:29 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory			g_mem;
extern pthread_mutex_t	g_mutex;

void		get_size(size_t page_s, size_t (*malloc_size)[2])
{
	int		i;
	int		nb_alloc;
	int		j;

	nb_alloc = 100;
	(*malloc_size)[0] = TINY * nb_alloc;
	(*malloc_size)[1] = SMALL * nb_alloc;
	i = -1;
	j = 0;
	while (++i < 2 && (j = 0) == 0)
		while ((((*malloc_size)[i]) = ((((*malloc_size)[i]) / (nb_alloc + j)) *
			(nb_alloc + j + 1))) % page_s != 0)
			j++;
}

void		*malloc(size_t size)
{
	size_t	page_size;
	size_t	malloc_size[2];

	pthread_mutex_init(&g_mutex, NULL);
	pthread_mutex_lock(&g_mutex);
	page_size = getpagesize();
	get_size(page_size, &malloc_size);
	if (g_mem.stack[0] == NULL)
	{
		if (!init_stack(page_size, malloc_size) ||
		!init_mem(malloc_size))
			return (NULL);
	}
	else if (!check_place(size) && !new_page(size, malloc_size, page_size))
		return (NULL);
	return (allocate(size));
}
