/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:52:57 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/12 18:00:11 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

// extern t_mall	*mall;
extern void	*stack;

int			init_tiny(size_t len)
{
	t_mall	*tmp_mall;
	void	*tmp;

	if (!(tmp = mmap(0, len, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
	return (0);
	tmp_mall = (t_mall*)stack;
	// printf("passe, %p\t\t %p\n", tmp, stack);
	tmp_mall->ptr = tmp;
	tmp_mall->type = 't';
	tmp_mall->use = 'n';
	tmp_mall->next = NULL;
	return (1);
}

int				init_small(size_t malloc_size[2])
{
	void	*tmp;
	t_mall	*tmp_mall;

	if (!(tmp = mmap(0, malloc_size[1], PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (0);
	tmp_mall = (t_mall*)stack + (sizeof(t_mall) * TINY);
	tmp_mall->ptr = tmp;
	tmp_mall->type = 's';
	tmp_mall->use = 'n';
	tmp_mall->next = NULL;
		return (1);
}

void			space(int loop, char type, size_t len)
{
	t_mall	*tmp_mall;
	t_mall	*new_mall;

	tmp_mall = (t_mall*)stack + (sizeof(t_mall) * (loop - 1));
	new_mall = (t_mall*)stack + (sizeof(t_mall) * (loop));
	new_mall->ptr = tmp_mall->ptr + len;
	new_mall->type = type;
	new_mall->use = 'n';
	tmp_mall->next = new_mall;
	new_mall->next = NULL;
}

int				init_mem(size_t malloc_size[2], size_t page_size)
{
	int		tiny;
	int		small;
	int		loop;

	tiny = malloc_size[0] / TINY;
	small = malloc_size[1] / SMALL;
	loop = 0;
	if (!init_tiny(malloc_size[0]) || !init_small(malloc_size))
		return (0);
	while (++loop < (malloc_size[0] / TINY + malloc_size[1] / SMALL) - 2)
		space(loop, (loop < malloc_size[0] / TINY) ? 't' : 's',
				(loop < malloc_size[0] / TINY) ? TINY : SMALL);
	return (1);
}