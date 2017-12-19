/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_pourcent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/24 18:11:46 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_flag_pourcent(t_print ptf, char **str)
{
	int len;

	len = 1;
	if (ptf.accuracy > 1 || ptf.zero > 1)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (!(ft_realloc_adr_p(str, len, ptf.ret)))
		return (0);
	if (ptf.moins == 1)
	{
		*str = ft_strcat(*str, "%");
		*str = ft_strnccat(*str, ' ', len - 1);
	}
	else
	{
		if (ptf.zero > 0)
			*str = ft_strnccat(*str, ' ', len - 1);
		else if (ptf.accuracy > 0)
			*str = ft_strnccat(*str, '0', len - 1);
		*str = ft_strcat(*str, "%");
	}
	return (len);
}
