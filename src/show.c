/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:43:00 by tferrari          #+#    #+#             */
/*   Updated: 2017/11/13 18:07:05 by tferrari         ###   ########.fr       */
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

void	print(t_mall *tmp)
{
	ft_printf("%p", tmp->ptr);
	ft_printf(" - ");
	ft_printf("%p", tmp->ptr + tmp->len);
	ft_printf(" : ");
	ft_printf("%zu", tmp->len);
	ft_printf(" octets\n");
}

void	show_alloc_mem(void)
{
	t_mall	*tmp;
	int		i;
	size_t	tot;

	i = -1;
	tot = 0;
	while (++i < 3)
	{
		tmp = (t_mall *)g_stack[i];
		new_zone(i, tmp);
		while (tmp)
		{
			if (tmp->use == 'y')
			{
				print(tmp);
				tot += tmp->len;
			}
			tmp = tmp->next;
		}
	}
	ft_printf("Total : %zu", tot);
}
