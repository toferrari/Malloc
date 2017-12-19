/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbletter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/02 19:37:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_nbletter(char *s, char c, int *nbletter, int nbword)
{
	int		i[2];
	int		letter;

	i[0] = 0;
	letter = 0;
	i[1] = 0;
	if (nbword == 0)
	{
		nbletter[0] = 1;
		return (nbletter);
	}
	while (s[i[0]])
	{
		while (s[i[0]] == c)
			i[0]++;
		letter++;
		if (s[i[0] + 1] == c || s[i[0] + 1] == '\0')
		{
			nbletter[i[1]] = letter;
			letter = 0;
			i[1]++;
		}
		i[0]++;
	}
	return (nbletter);
}
