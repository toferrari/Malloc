/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:57:59 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/30 16:55:30 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory		g_mem;

int			check_large(void)
{
	t_mall	*tmp;
	size_t	i;
	size_t	len;

	tmp = (t_mall*)g_mem.stack[2];
	i = -1;
	while (((len = ++i * sizeof(t_mall)) < g_mem.page_tot[2] &&
			tmp && tmp->use == 'y'))
		tmp = tmp->next;
	if (len == g_mem.page_tot[2])
		return (0);
	return (1);
}

int			check_place(size_t size)
{
	t_mall *tmp;

	if (size <= SMALL)
		tmp = (t_mall*)g_mem.stack[TAB(size)];
	else if (size > SMALL && !check_large())
		return (0);
	else
		tmp = (t_mall*)g_mem.stack[2];
	while (tmp && tmp->use != 'n')
		tmp = tmp->next;
	if (size <= SMALL && !tmp)
		return (0);
	return (1);
}
