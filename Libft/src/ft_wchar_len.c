/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:47:07 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/01 18:35:53 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define INTLEN(x) (x % 6 != 0) ? (x / 6 + 1) : (x / 6);

int		ft_wchar_len(wchar_t c)
{
	int len;

	len = ft_intlen_base(c, 2);
	if (len > 16)
		return (4);
	else if (len > 11)
		return (3);
	else if (len > 7)
		return (2);
	else
		return (1);
	return (len);
}
