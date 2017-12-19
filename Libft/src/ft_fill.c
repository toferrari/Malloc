/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/12/08 13:39:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_back0(char **d, int i, int k)
{
	d[i][k] = '\0';
	d[i + 1] = 0;
	return (d);
}

char	**ft_back1(char **d, int *j, int *k)
{
	d[*j][*k] = '\0';
	*k = 0;
	*j += 1;
	return (d);
}

char	**ft_fill(char **d, char *s, char c, int nbword)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	j = 0;
	i = 0;
	if (nbword == 0)
		return (d = ft_back0(d, i, k));
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			d[j][k] = s[i];
			i++;
			k++;
		}
		if (j < nbword)
			d = ft_back1(d, &j, &k);
	}
	return (d);
}
