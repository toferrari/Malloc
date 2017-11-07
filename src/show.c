/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:43:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/11/07 10:09:10 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*g_stack[3];

void	new_zone(int i, t_mall *tmp)
{
	if (i == 0)
		ft_printf("TINY : %p\n", tmp);
	else if (i == 1)
		ft_printf("SMALL : %p\n", tmp);
	else
		ft_printf("LARGE : %p\n", tmp);
}

void	show_alloc_mem(void)
{
	t_mall	*tmp;
	int		nb;
	int		i;
	size_t	tot;

	nb = 0;
	i = -1;
	tot = 0;
	while (++i < 3)
	{
		tmp = (t_mall *)stack[i];
		new_zone(i, tmp);
		while (tmp)
		{
			if (tmp->use == 'y')
			{
				ft_printf("%p - %p : %zu octets\n", tmp->ptr, tmp->ptr + \
				tmp->len, tmp->len);
				tot += tmp->len;
			}
			tmp = tmp->next;
		}
	}
	ft_printf("Total : %zu", tot);
}
