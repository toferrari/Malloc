/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:15:14 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/30 19:56:02 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long n, int base)
{
	long long	nb;

	nb = (long long)n;
	if (nb < 0)
	{
		nb = -nb;
		ft_putchar('-');
	}
	if (nb <= base - 1 && nb <= 9)
		ft_putchar(nb + '0');
	else if (nb <= base - 1)
		ft_putchar(nb - 10 + 'a');
	else
	{
		ft_putnbr_base(nb / base, base);
		ft_putnbr_base(nb % base, base);
	}
}
