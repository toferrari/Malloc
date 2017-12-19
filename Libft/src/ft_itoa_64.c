/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_64.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/22 15:27:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_64(int64_t n)
{
	int64_t		len;
	uint64_t	nb;
	int64_t		i;
	char		*s;

	len = ft_intlen_64(n);
	i = 0;
	nb = (n < 0) ? (uint64_t)-n : (uint64_t)n;
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
