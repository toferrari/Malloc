/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:41:36 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/30 19:01:37 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory		g_mem;

void	*realloc_bigger(t_mall *tmp_mall, size_t size)
{
	void	*new;

	if ((new = mmap(0, size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (0);
	new = ft_memcpy(new, tmp_mall->ptr, tmp_mall->len);
	tmp_mall->ptr = new;
	tmp_mall->len = size;
	pthread_mutex_unlock(&g_mutex);
	pthread_mutex_destroy(&g_mutex);
	return (tmp_mall->ptr);
}

void	*same_zone(t_mall *tmp_mall, size_t size)
{
	tmp_mall->len = size;
	pthread_mutex_unlock(&g_mutex);
	pthread_mutex_destroy(&g_mutex);
	return (tmp_mall->ptr);
}

void	*new_mall(t_mall *tmp_mall, size_t size)
{
	size_t	i;
	t_mall	*new;
	void	*tmp;

	i = (size <= SMALL) ? 1 : 2;
	new = (t_mall*)(g_mem.stack[i]);
	tmp = malloc(size);
	while (new && tmp != new->ptr)
		new = new->next;
	tmp_mall->len = 0;
	tmp_mall->use = 'n';
	new->ptr = ft_memcpy(new->ptr, tmp_mall->ptr, tmp_mall->len);
	pthread_mutex_unlock(&g_mutex);
	pthread_mutex_destroy(&g_mutex);
	return (new->ptr);
}

void	*realloc(void *ptr, size_t size)
{
	t_mall			*tmp_mall;

	pthread_mutex_init(&g_mutex, NULL);
	pthread_mutex_lock(&g_mutex);
	if (!ptr)
		return (malloc(size));
	tmp_mall = found_it(ptr);
	if (!tmp_mall)
		return (NULL);
	if (size > SMALL && size > tmp_mall->len)
		return (realloc_bigger(tmp_mall, size));
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
