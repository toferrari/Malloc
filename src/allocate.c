/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:03:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/12/19 13:34:42 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*g_stack[3];

void		*large(size_t size)
{
	t_mall	*large;
	t_mall	*tmp_mall;

	tmp_mall = (t_mall *)(g_stack[2]);
	while (tmp_mall->next && tmp_mall->use != 'n')
		tmp_mall = tmp_mall->next;
	if (tmp_mall->use == 'n')
		large = tmp_mall;
	else
		large = tmp_mall + 1;
	if ((large->ptr = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	large->use = 'y';
	large->len = size;
	tmp_mall->next = large;
	large->next = NULL;
	return (large->ptr);
}

void		*allocate(size_t size)
{
	t_mall	*tmp;
	void	*ptr;

	tmp = (t_mall *)g_stack[TAB(size)];
	if (size <= SMALL)
		while (tmp && (tmp->use != 'n'))
			tmp = tmp->next;
	else
		return (large(size));
	tmp->use = 'y';
	tmp->len = size;
	return (tmp->ptr);
}
