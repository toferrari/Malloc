/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:42:37 by tferrari          #+#    #+#             */
/*   Updated: 2017/01/16 18:59:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_realloc_chr(char *src, int size)
{
	char	*dest;

	if (size < 0)
		return (NULL);
	if (size == 0)
		return (src);
	if (!(dest = ft_strnew(ft_strlen(src) + size)))
		return (NULL);
	dest = ft_strcpy(dest, src);
	ft_memdel((void **)src);
	src = NULL;
	return (dest);
}
