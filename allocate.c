/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 16:03:32 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/16 15:58:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*stack;

void		*large(size_t size, size_t malloc_size[2])
{
	t_mall	*large;
	t_mall	*tmp_mall;
	size_t	s_large;
	int		i;

	s_large = (malloc_size[0] / TINY) + (malloc_size[1] / SMALL);
	i = 0;
	tmp_mall = (t_mall*)stack + (sizeof(t_mall) * (s_large - 1));
	printf("passe\n");
	if (tmp_mall->next)
		while ((tmp_mall = tmp_mall->next) || (tmp_mall->use == 'n' ))
			i++;
	large = (t_mall*)stack + (sizeof(t_mall) * (s_large + i));
	if (!(large->ptr = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	large->type = 'l';
	large->use = 'n';
	// large->len = size;
	tmp_mall->next = large;
	large->next = NULL;
	return (large->ptr);

}

void		*allocate(size_t size, size_t malloc_size[2])
{
	t_mall *tmp;
	void	*ptr;

	if (size <= TINY)
		tmp = (t_mall *)stack;
	else if (size <= SMALL)
		tmp = (t_mall *)stack + (sizeof(t_mall) * TINY);
	else
		return (large(size, malloc_size));
	while (tmp && tmp->use != 'n')
		tmp = tmp->next;
	tmp->use = 'y';
	// tmp->len = size;
	return (tmp->ptr);
}
