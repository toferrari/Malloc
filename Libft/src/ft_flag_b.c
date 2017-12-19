/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 12:29:34 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/24 17:23:59 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int				ft_flag_b(t_print ptf, unsigned int nb, char **str)
{
	int len;

	len = ft_intlen_base(nb, 2);
	if (ft_realloc_adr_p(str, len, ptf.ret) == 0 ||
	!(ptf.tmp = ft_itoa_base(nb, 2)))
		return (0);
	*str = ft_strcat_p(*str, ptf.tmp, ptf.ret);
	ft_memdel((void **)&ptf.tmp);
	return (len);
}
