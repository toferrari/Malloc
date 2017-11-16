/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:41:36 by tferrari          #+#    #+#             */
/*   Updated: 2017/11/06 18:12:02 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern size_t	g_page_tot[3];
extern void		*g_stack[3];

void	*same_zone(t_mall *tmp_mall, size_t size)
{
	tmp_mall->len = size;
	return (tmp_mall->ptr);
}

void	*new_mall(t_mall *tmp_mall, size_t size)
{
	size_t	i;
	t_mall	*new;
	void	*tmp;

	i = (size <= SMALL) ? 1 : 2;
	new = (t_mall*)(g_stack[i]);
	tmp = malloc(size);
	while (new && tmp != new->ptr)
		new = new->next;
	tmp_mall->len = 0;
	tmp_mall->use = 'n';
	new->ptr = ft_memcpy(new->ptr, tmp_mall->ptr, tmp_mall->len);
	return (new->ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_mall			*tmp_mall;

	if (!ptr)
		return (malloc(size));
	tmp_mall = found_it(ptr);
	if (!tmp_mall)
		return (NULL);
	if ((size <= TINY && tmp_mall->len <= TINY) ||
	(tmp_mall->len <= SMALL && tmp_mall->len > TINY && size <= SMALL) ||
	(tmp_mall->len > SMALL && tmp_mall->len <= size) ||
	(tmp_mall->len >= size && tmp_mall->len > SMALL))
		return (same_zone(tmp_mall, size));
	if ((tmp_mall->len <= TINY && size > TINY && size <= SMALL) ||
	(size > SMALL && tmp_mall->len <= SMALL))
		return (new_mall(tmp_mall, size));
	return (NULL);
}
