/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/02 19:37:22 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		count;
	int		i;
	char	*cpy;

	count = ft_strlen(str);
	i = 0;
	if (!(cpy = (char *)malloc((count + 1) * sizeof(char))))
		return (0);
	while (str[i])
	{
		cpy[i] = (char)str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
