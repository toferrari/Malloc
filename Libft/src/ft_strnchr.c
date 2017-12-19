/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 14:51:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/08 14:55:46 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(char *src, char *find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (find[i])
	{
		while (src[j])
		{
			if (find[i] == src[j])
				return (&src[j]);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
