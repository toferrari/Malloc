/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:03:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/12 18:30:29 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*stack;

void		*allocate(size_t size)
{
	t_mall *tmp;
	void	*ptr;

	if (size <= TINY)
		tmp = (t_mall *)stack;
	else if (size <= SMALL)
		tmp = (t_mall *)stack + (sizeof(t_mall) * TINY);
	while (tmp && tmp->use != 'n')
		tmp = tmp->next;
	tmp->use = 'y';
	printf("ptr = %p\n", tmp->ptr);
	return (tmp->ptr);
}
