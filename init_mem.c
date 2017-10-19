/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:52:57 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/19 16:12:39 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*stack[3];

int			init_tiny(size_t len)
{
	t_mall	*tmp_mall;
	void	*tmp;

	if (!(tmp = mmap(0, len, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	tmp_mall = (t_mall*)(stack[0]);
	tmp_mall->ptr = tmp;
	tmp_mall->use = 'n';
	tmp_mall->next = NULL;
	return (1);
}

int				init_small(size_t malloc_size)
{
	void	*tmp;
	t_mall	*tmp_mall;
	t_mall	*new_mall;

	if (!(tmp = mmap(0, malloc_size, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	new_mall = (t_mall*)(stack[1]);
	new_mall->ptr = tmp;
	new_mall->use = 'n';
	new_mall->len = 0;
	new_mall->next = NULL;
	return (1);
}

void			space(int *loop, char type, size_t len, size_t page_size)
{
	t_mall	*tmp_mall;
	t_mall	*new_mall;
	void	*tmp;

	// printf("type = %d\n", type);
	tmp_mall = (t_mall*)(stack[type]);
	while (tmp_mall->next)
		tmp_mall = tmp_mall->next;
	new_mall = tmp_mall + 1;
	new_mall->ptr = tmp_mall->ptr + len;
	new_mall->use = 'n';
	new_mall->len = len;
	tmp_mall->next = new_mall;
	new_mall->next = NULL;
	// printf("adr t_mall = %p, adr ptr = %p, loop = %d, type = %d\n", new_mall, tmp_mall->ptr, *loop, type);
}

int				init_mem(size_t malloc_size[2], size_t page_size)
{
	int		tiny;
	int		small;
	int		loop;

	tiny = malloc_size[0] / TINY;
	small = malloc_size[1] / SMALL;
	loop = -1;
	while (++loop < (malloc_size[0] / TINY + malloc_size[1] / SMALL) - 1)
	{
		if (loop == 0)
		{
			if (!init_tiny(malloc_size[0]))
				return (0);
		}
		else if (loop == TINY)
		{
			if (!init_small(malloc_size[1]))
				return (0);
		}
		else
			space(&loop, (loop < malloc_size[0] / TINY) ? 0 : 1,
		 		(loop < malloc_size[0] / TINY) ? TINY : SMALL, page_size);
	}
	return (1);
}
