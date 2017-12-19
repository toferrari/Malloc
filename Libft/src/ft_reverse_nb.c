/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/02 19:37:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_reverse_nb(char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = ft_strlen(s) - 1;
	if (!(d = (char *)malloc((j + 2) * sizeof(char))))
		return (NULL);
	if (s[i] == '-')
	{
		d[i] = '-';
		i++;
	}
	while (s[i])
	{
		d[i] = s[j];
		i++;
		j--;
	}
	d[i] = '\0';
	return (d);
}
