/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:06:19 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/30 16:50:30 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory		g_mem;

int				init_stack(size_t page_size, size_t malloc_size[2])
{
	int		i;
	size_t	size[3];

	i = -1;
	while (++i < 2)
	{
		size[i] = (sizeof(t_mall) * malloc_size[i]) / (i == 0 ? TINY : SMALL);
		if ((g_mem.stack[i] = mmap(0, size[i], PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (0);
		g_mem.page_tot[i] += size[i] * page_size;
	}
	if ((g_mem.stack[2] = mmap(0, page_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (0);
	g_mem.page_tot[2] += page_size;
	return (1);
}
