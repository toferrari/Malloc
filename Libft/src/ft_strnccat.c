/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnccat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:11:13 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/09 20:22:49 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnccat(char *dest, char c, int n)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(dest);
	while (i < n)
	{
		dest[j] = c;
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
