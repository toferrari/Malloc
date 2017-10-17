/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 12:06:19 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/17 13:30:18 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void		*stack;
extern size_t	page_tot;

void			*new_page(size_t page_size)
{
	void	*stack;

	if (!(stack = mmap(0, page_size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	page_tot += page_size;
	return (stack);
}

int				init_stack(size_t len)
{
	if (!(stack = mmap(0, len, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	page_tot += len;
	return (1);
}
