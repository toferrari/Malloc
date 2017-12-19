/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:40:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/26 15:35:49 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, unsigned int nb, int *len_i)
{
	if (len_i[1] == 2 && nb != 0)
		*str = (ptf.c == 'X') ? ft_strcat(*str, "0X") : ft_strcat(*str, "0x");
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len_i[0]);
	if (nb > 0)
		*str = (ptf.c == 'X') ? ft_strcat(*str, ft_strupper(
		ptf.tmp)) : ft_strcat(*str, ptf.tmp);
	if (ptf.accuracy < ptf.zero)
		*str = ft_strnccat(*str, ' ', ptf.zero - len_i[0] - len_i[1]);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len_i[1]);
}

static void	ft_moin_off(char **str, t_print ptf, unsigned int nb, int *len_i)
{
	int len;

	len = (nb == 0) ? 0 : len_i[0];
	if (ptf.accuracy == 0 || len > ptf.accuracy)
		*str = ft_strnccat(*str, ' ', ptf.zero - len - len_i[1]);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len_i[1]);
	if (len_i[1] == 2 && nb != 0)
		*str = (ptf.c == 'X') ? ft_strcat(*str, "0X") : ft_strcat(*str, "0x");
	if (ptf.htag == 1 && ptf.bool_acc == 1 && len_i[0] < ptf.accuracy)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len);
	else if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len - len_i[1]);
	if (!(nb == 0 && ptf.bool_acc == 1 && ptf.accuracy == 0))
		*str = (ptf.c == 'X') ? ft_strcat(*str, ft_strupper(
		ptf.tmp)) : ft_strcat(*str, ptf.tmp);
}

static int	ft_convert_len_acc(t_print ptf, unsigned int nb, int len)
{
	int ret;

	if (nb == 0 && ptf.bool_acc == 1 && ptf.accuracy == 0 && ptf.zero == 0)
		return (0);
	ret = len;
	if (ptf.zero > len || ptf.accuracy > len)
		ret = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if ((ptf.accuracy == 0 && ptf.zero == 0 && ptf.htag == 1 && nb != 0) ||
	(ptf.htag == 1 && ptf.bool_acc == 1 && len < ptf.accuracy))
		ret += 2;
	return (ret);
}

int			ft_flag_hexa(t_print ptf, unsigned int nb, char **str)
{
	int len_i[2];
	int ret;

	len_i[0] = ft_intlen_base(nb, 16);
	ret = ft_convert_len_acc(ptf, nb, len_i[0]);
	if (ft_realloc_adr_p(str, ret, ptf.ret) == 0 ||
	!(ptf.tmp = ft_itoa_base(nb, 16)))
		return (0);
	len_i[1] = (ptf.htag == 1) ? 2 : 0;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, len_i);
	else
		ft_moin_off(str, ptf, nb, len_i);
	ft_memdel((void **)&ptf.tmp);
	return (ret);
}
