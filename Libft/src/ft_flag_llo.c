/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_llo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:40:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/28 20:55:07 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, uint64_t nb, int i)
{
	if (i == 1)
		*str = ft_strcat(*str, "0");
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_base64(nb, 8));
	*str = (ptf.c == 'X') ? ft_strcat(*str, ptf.tmp) :
	ft_strcat(*str, ptf.tmp);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base64(nb, 8) - i);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - i);
}

static void	ft_moin_off(char **str, t_print ptf, uint64_t nb, int i)
{
	int len;

	len = ft_intlen_base64(nb, 8);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - len - i);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - i);
	if (ptf.accuracy > 0 && nb != 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len);
	if (ptf.accuracy == 0 && i == 1 && nb != 0)
		*str = ft_strcat(*str, "0");
	if (nb != 0)
		*str = ft_strcat(*str, ptf.tmp);
	else if (nb == 0 && ptf.zero == 0 && ptf.accuracy == 0)
		*str = ft_strcat(*str, ptf.tmp);
}

static int	ft_convert_len_acc(t_print ptf, uint64_t nb)
{
	int len;

	if (nb == 0 && ptf.htag == 0 && ptf.accuracy == 0 && ptf.zero == 0 &&
	ptf.bool_acc == 1)
		return (0);
	if (nb == 0 && ptf.htag == 1 && ptf.accuracy == 0 && ptf.zero == 0)
		return (1);
	len = ft_intlen_base64(nb, 8);
	if (ptf.zero == 0 && ptf.accuracy == 0 && ptf.bool_acc == 1)
		return (0);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.accuracy == 0 && ptf.zero == 0 && ptf.htag == 1)
		len++;
	return (len);
}

int			ft_flag_llo(t_print ptf, uint64_t nb, char **str)
{
	int len;
	int i;

	len = ft_convert_len_acc(ptf, nb);
	if (ft_realloc_adr_p(str, len, ptf.ret) == 0 ||
	!(ptf.tmp = ft_itoa_base64(nb, 8)))
		return (0);
	i = ptf.htag;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	ft_memdel((void **)&ptf.tmp);
	return (len);
}
