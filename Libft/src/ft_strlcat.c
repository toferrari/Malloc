/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/24 15:58:30 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t sd;

	sd = 0;
	i = 0;
	while (dest[sd] && sd < size)
		sd++;
	while (sd + i < size - 1 && src[i])
	{
		dest[sd + i] = src[i];
		i++;
	}
	if (sd < size)
		dest[sd + i] = '\0';
	return (sd + ft_strlen(src));
}
