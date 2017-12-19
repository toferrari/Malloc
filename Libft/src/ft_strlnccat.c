/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlnccat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:11:13 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/09 13:22:21 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlnccat(char *dest, char c, int *start, int len)
{
	int end;

	end = *start + len;
	while (*start < end)
	{
		dest[*start] = c;
		(*start)++;
	}
	dest[end] = '\0';
	return (dest);
}
