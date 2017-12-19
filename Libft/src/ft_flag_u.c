/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/24 18:14:05 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, unsigned int nb,
unsigned int len)
{
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_base(nb, 10));
	*str = ft_strcat(*str, ptf.tmp);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base(nb, 10) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, unsigned int nb,
unsigned int len)
{
	if (ptf.accuracy == 0 || (ptf.accuracy < ft_intlen_base(nb, 10)))
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base(nb, 10) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_base(nb, 10));
	*str = ft_strcat(*str, ptf.tmp);
}

static int	ft_convert_len_acc_u(t_print ptf, unsigned int nb)
{
	int len;

	len = ft_intlen_base(nb, 10);
	if (nb == 0 && ptf.bool_acc == 1)
		return (0);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if ((ptf.space == 1 || ptf.plus == 1) && ptf.c != 'u')
		len++;
	return (len);
}

int			ft_flag_u(t_print ptf, unsigned int nb, char **str)
{
	int	len;
	int	i;

	len = ft_convert_len_acc_u(ptf, nb);
	if (len == 0 || !(ptf.tmp = ft_itoa_base(nb, 10)) ||
	ft_realloc_adr_p(str, len, ptf.ret) == 0)
		return (0);
	i = ft_convert_signe(str, ptf, nb);
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, (unsigned int)i);
	else
		ft_moin_off(str, ptf, nb, (unsigned int)i);
	ft_memdel((void **)&ptf.tmp);
	return (len);
}
