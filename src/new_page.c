/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_page.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:53:59 by tferrari          #+#    #+#             */
/*   Updated: 2017/11/07 09:40:08 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*g_stack[3];

int			first_mall(int type, size_t malloc_size)
{
	t_mall	*tmp;
	t_mall	*new;
	void	*n_stack;
	size_t	len;

	tmp = (t_mall*)stack[type];
	new = (t_mall*)stack[type];
	while (tmp->next)
		tmp = tmp->next;
	len = (sizeof(t_mall) * malloc_size / (type == 0 ? TINY : SMALL));
	if (!(n_stack = mmap(0, len, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	tmp->next = n_stack;
	new = (t_mall*)n_stack;
	if (!(new->ptr = mmap(0, len, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	new->use = 'n';
	new->len = 0;
	new->next = NULL;
	return (1);
}

int			new_large(size_t page_size)
{
	t_mall	*tmp;
	t_mall	*new;
	void	*n_stack;

	tmp = (t_mall*)stack[2];
	new = (t_mall*)stack[2];
	while (tmp->next)
		tmp = tmp->next;
	if (!(n_stack = mmap(0, page_size, PROT_READ | PROT_WRITE,
		MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	tmp->next = n_stack;
	new = (t_mall*)n_stack;
	new->ptr = NULL;
	new->use = 'n';
	new->len = 0;
	new->next = NULL;
	page_tot[2] += page_size;
	return (1);
}

int			new_page(size_t size, size_t malloc_size[2], size_t page_size)
{
	int		type;
	t_mall	*tmp;
	int		i;

	type = (size > SMALL) ? 2 : 1;
	type = (size <= TINY) ? 0 : 1;
	tmp = (t_mall*)stack[type];
	if (type < 2 && !first_mall(type, malloc_size[type]))
		return (0);
	else if (!new_large(page_size))
		return (0);
	i = (type == 0) ? TINY : SMALL;
	while (size <= SMALL && --i >= 0)
		space(type, size);
	return (1);
}
