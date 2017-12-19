/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/24 15:51:25 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloctab(int *i, int nbword, char **d, int *nbletter)
{
	while (*i < nbword)
	{
		if (!(d[*i] = (char *)malloc((nbletter[*i] + 1) * sizeof(char))))
			return (NULL);
		*i += 1;
	}
	return (d);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**d;
	int		nbword;
	int		*nbletter;
	int		i;

	if (s == NULL)
		return (NULL);
	nbword = ft_nbword((char *)s, c);
	i = 0;
	if (!(nbletter = (int *)malloc((nbword + 1) * sizeof(int))))
		return (NULL);
	nbletter = ft_nbletter((char *)s, c, nbletter, nbword);
	if (!(d = (char **)malloc((nbword + 1) * sizeof(char *))))
		return (NULL);
	if (nbword == 0)
	{
		if (!(d[i] = (char *)malloc((nbletter[i] + 1) * sizeof(char))))
			return (NULL);
	}
	if (!(d = ft_malloctab(&i, nbword, d, nbletter)))
		return (NULL);
	d = ft_fill(d, (char *)s, c, nbword);
	d[i] = NULL;
	return (d);
}
