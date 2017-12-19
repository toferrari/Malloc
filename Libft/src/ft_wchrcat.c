/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchrcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/02 12:05:30 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wchrcat(char *dest, const char *src, int start, int len)
{
	int end;
	int i;

	end = start + len;
	i = 0;
	while (start + i < end)
	{
		dest[start + i] = src[i];
		i++;
	}
	dest[end] = '\0';
	return (dest);
}
