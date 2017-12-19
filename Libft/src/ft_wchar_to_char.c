/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_to_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:30:48 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/02 18:30:00 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		*ft_wchar_to_char(wchar_t c, char *dest)
{
	int		chr_len;
	int		i;

	chr_len = ft_wchar_len(c);
	i = 1;
	if (chr_len > 1)
	{
		while (i < chr_len)
		{
			dest[chr_len - i] = (c & 0x3F);
			dest[chr_len - i] += 0x80;
			c = c >> 6;
			i++;
		}
		dest[0] = (0xF0 << (4 - chr_len) | c);
	}
	else
		dest[0] = c;
	return (dest);
}
