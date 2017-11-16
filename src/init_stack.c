/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:06:19 by tferrari          #+#    #+#             */
/*   Updated: 2017/11/06 18:12:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern size_t	g_page_tot[3];
extern void		*g_stack[3];

int				init_stack(size_t page_size, size_t malloc_size[2])
{
	int		i;
	size_t	size[3];

	i = -1;
	while (++i < 2)
	{
		size[i] = (sizeof(t_mall) * malloc_size[i]) / (i == 0 ? TINY : SMALL);
		if (!(g_stack[i] = mmap(0, size[i], PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (0);
		g_page_tot[i] += size[i] * page_size;
	}
	if (!(g_stack[2] = mmap(0, page_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	g_page_tot[2] += page_size;
	return (1);
}
