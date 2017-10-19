/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:06:19 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/19 15:55:46 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void		*stack[3];
extern size_t	page_tot[3];

// void			*new_page(size_t page_size)
// {
// 	void	*stack;
//
// 	if (!(stack = mmap(0, page_size, PROT_READ | PROT_WRITE,
// 			MAP_ANON | MAP_PRIVATE, -1, 0)))
// 		return (NULL);
// 	page_tot += page_size;
// 	return (stack);
// }

int				init_stack(size_t page_size, size_t malloc_size[2])
{
	int		i;
	size_t	size[3];

	i = -1;
	while (++i < 2)
	{
		size[i] = (malloc_size[i] / page_size) + 1;
		if (!(stack[i] = mmap(0, size[i], PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (0);
		printf("%p\n", stack[i]);
		page_tot[i] += size[i] * page_size;
	}
	return (1);
}
