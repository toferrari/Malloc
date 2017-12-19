/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/22 14:57:51 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MODULO(x) (x <= 9) ? (x + '0') : (x - 10 + 'a');

char	*ft_itoa_base64(uint64_t nb, int base)
{
	int				len;
	char			*s;

	len = ft_intlen_base64(nb, base);
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
