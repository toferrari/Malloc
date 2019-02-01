/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 16:52:57 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/31 11:51:34 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory		g_mem;

int				init_both(size_t len, int type)
{
	t_mall	*tmp_mall;
	void	*tmp;

	if ((tmp = mmap(0, len, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (0);
	tmp_mall = (t_mall*)(g_mem.stack[type]);
	tmp_mall->ptr = tmp;
	tmp_mall->use = 'n';
	tmp_mall->len = 0;
	tmp_mall->next = NULL;
	return (1);
}

void			init_large(void)
{
	t_mall	*large;

	large = (t_mall *)(g_mem.stack[2]);
	large->ptr = NULL;
	large->use = 'n';
	large->len = 0;
	large->next = NULL;
}

void			space(int type, size_t len)
{
	t_mall	*tmp_mall;
	t_mall	*new_mall;

	tmp_mall = (t_mall*)(g_mem.stack[type]);
	while (tmp_mall->next)
		tmp_mall = tmp_mall->next;
	new_mall = tmp_mall + 1;
	new_mall->ptr = tmp_mall->ptr + len;
	new_mall->use = 'n';
	new_mall->len = 0;
	tmp_mall->next = new_mall;
	new_mall->next = NULL;
}

int				init_mem(size_t malloc_size[2])
{
	int		tiny;
	int		small;
	int		loop;

	tiny = malloc_size[0] / TINY;
	small = malloc_size[1] / SMALL;
	loop = -1;
	while (++loop < (tiny + small))
	{
		if ((loop == 0 || loop == TINY) &&
		!init_both((loop < tiny) ? malloc_size[0] : malloc_size[1],
		(loop < tiny) ? 0 : 1))
			return (0);
		else if (loop != 0 && loop != TINY)
			space(((unsigned long)loop < malloc_size[0] / TINY) ? 0 : 1,
				(loop < tiny) ? TINY : SMALL);
	}
	init_large();
	return (1);
}
