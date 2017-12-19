/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:47:07 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/02 17:10:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wstr_len(wchar_t *str)
{
	int len;
	int i;

	len = 0;
	i = 0;
	while (str[i])
	{
		len += ft_wchar_len(str[i]);
		i++;
	}
	return (len);
}
