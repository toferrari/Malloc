/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:03:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/31 19:13:42 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*stack[3];

void		*init_large(size_t size)
{
	t_mall	*large;

	large = (t_mall *)(stack[2]);
	if (!(large->ptr = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	large->use = 'y';
	large->len = size;
	large->next = NULL;
	return (large);
}

void		*large(size_t size)
{
	t_mall	*large;
	t_mall	*tmp_mall;

	tmp_mall = (t_mall *)(stack[2]);
	large = NULL;
	if (!tmp_mall || !(large = init_large(size)))
		return (NULL);
	else if (!large)
	{
		while (tmp_mall->next && tmp_mall->use != 'n')
			tmp_mall = tmp_mall->next;
		large = tmp_mall + 1;
		if (!(large->ptr = mmap(0, size, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0)))
			return (NULL);
		large->use = 'y';
		large->len = size;
		tmp_mall->next = large;
		large->next = NULL;
	}
	return (large->ptr);

}

void		*allocate(size_t size)
{
	t_mall *tmp;
	void	*ptr;

	tmp = (t_mall *)stack[TAB(size)];
	if (size < SMALL)
		while (tmp && (tmp->use != 'n'))
			tmp = tmp->next;
	else
		return (large(size));
	tmp->use = 'y';
	tmp->len = size;
	return (tmp->ptr);
}
