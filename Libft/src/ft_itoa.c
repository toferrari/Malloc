/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/10 16:04:21 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				len;
	unsigned int	nb;
	int				i;
	char			*s;

	len = ft_intlen(n);
	i = 0;
	nb = (n < 0) ? (unsigned int)-n : (unsigned int)n;
	if (!(s = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		s[0] = '-';
		i++;
	}
	n = len;
	while (i < len)
	{
		s[len - 1] = nb % 10 + 48;
		nb = nb / 10;
		len--;
	}
	s[n] = '\0';
	return (s);
}
