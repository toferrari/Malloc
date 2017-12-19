/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/24 14:48:56 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numbersp(const char *s, int j)
{
	while ((s[j] == ' ' || s[j] == '\n' || s[j] == '\t') && (s[j]))
		j++;
	return (j);
}

static int		i_withoutsp(const char *s, int i)
{
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t' || s[i] == '\0')
	&& (i >= 0))
		i--;
	return (i);
}

static char		*ft_fill_trin(const char *s, char *d, int j, int i)
{
	int		k;

	k = 0;
	while ((j + k) <= i)
	{
		d[k] = s[j + k];
		k++;
	}
	d[k] = '\0';
	return (d);
}

char			*ft_strtrim(const char *s)
{
	int		i;
	int		j;
	char	*d;

	if (s == NULL)
		return (NULL);
	i = ft_strlen((char *)s);
	j = numbersp(s, 0);
	if (i == j)
	{
		if (!(d = (char *)malloc((1) * sizeof(char))))
			return (NULL);
		d[0] = '\0';
		return (d);
	}
	i = i_withoutsp(s, i);
	if (!(d = (char *)malloc((i - j + 2) * sizeof(char))) || s == NULL)
		return (NULL);
	d = ft_fill_trin(s, d, j, i);
	return (d);
}
