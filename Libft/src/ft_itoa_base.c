/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/22 18:11:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MODULO(x) (x <= 9) ? (x + '0') : (x - 10 + 'a');

char	*ft_itoa_base(unsigned int nb, int base)
{
	int				len;
	char			*s;

	len = ft_intlen_base(nb, base);
	if (!(s = ft_strnew(len)))
		return (NULL);
	while (0 < len)
	{
		s[len - 1] = MODULO(nb % base);
		nb = nb / base;
		len--;
	}
	return (s);
}
