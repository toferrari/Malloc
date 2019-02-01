/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:43:00 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/31 11:57:20 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory		g_mem;

void	new_zone(int i, t_mall *tmp)
{
	if (i == 0)
	{
		ft_putstr("TINY : 0x");
		ft_putnbr_base((long long)tmp, 16);
		ft_putchar('\n');
	}
	else if (i == 1)
	{
		ft_putstr("SMALL : 0x");
		ft_putnbr_base((long long)tmp, 16);
		ft_putchar('\n');
	}
	else
	{
		ft_putstr("LARGE : 0x");
		ft_putnbr_base((long long)tmp, 16);
		ft_putchar('\n');
	}
}

void	print(t_mall *tmp)
{
	ft_putnbr_base((long long)tmp->ptr, 16);
	ft_putstr(" - ");
	ft_putnbr_base((long long)tmp->ptr + tmp->len, 16);
	ft_putstr(" : ");
	ft_putnbr_base((long long)tmp->len, 10);
	ft_putstr(" octects\n");
}

void	print_total(size_t tot)
{
	ft_putstr("Total : ");
	ft_putnbr_base((long long)tot, 10);
	ft_putchar('\n');
}

void	show_alloc_mem(void)
{
	t_mall	*tmp;
	int		i;
	size_t	tot;

	pthread_mutex_init(&g_mutex, NULL);
	pthread_mutex_lock(&g_mutex);
	i = -1;
	tot = 0;
	while (++i < 3)
	{
		tmp = (t_mall *)g_mem.stack[i];
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
	print_total(tot);
	pthread_mutex_unlock(&g_mutex);
	pthread_mutex_destroy(&g_mutex);
}
