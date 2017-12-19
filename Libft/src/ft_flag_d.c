/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/24 18:08:47 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, int nb, int len)
{
	unsigned int unb;

	unb = (nb < 0) ? (unsigned int)-nb : nb;
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	if (ptf.plus == 1 && nb >= 0)
		*str = ft_strcat(*str, "+");
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - ft_intlen_base(unb, 10));
	*str = ft_strcat(*str, ptf.tmp);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - ft_intlen_base(unb, 10) - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, int nb, int len)
{
	unsigned int	unb;
	int				len_nb;

	unb = (nb < 0) ? (unsigned int)-nb : nb;
	len_nb = (nb == 0) ? 0 : ft_intlen_base(unb, 10);
	if (ptf.accuracy == 0 || ptf.accuracy < len_nb)
		*str = ft_strnccat(*str, ' ', ptf.zero - len_nb - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	if (ptf.plus == 1 && nb >= 0)
		*str = ft_strcat(*str, "+");
	if (nb == 0 && ptf.plus == 1 && ptf.zero == 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len_nb - 1);
	else if (ptf.zero == 0 && ptf.bool_acc != 1 && nb != 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - len_nb - len);
	else
		*str = ft_strnccat(*str, '0', ptf.accuracy - len_nb);
	if (nb != 0)
		*str = ft_strcat(*str, ptf.tmp);
	else if (nb == 0 && ptf.zero == 0 && ptf.accuracy == 0 && ptf.bool_acc == 0)
		*str = ft_strcat(*str, ptf.tmp);
}

static int	ft_convert_len_acc(t_print ptf, int nb)
{
	int len;

	if (nb == 0 && ptf.bool_acc == 1 && ptf.accuracy == 0 && ptf.zero == 0)
		return (0);
	len = ft_intlen(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	else if ((ptf.space == 1 || ptf.plus == 1) && nb >= 0)
		len++;
	if (ptf.bool_acc == 1 && nb < 0
		&& ft_intlen(nb) < ptf.accuracy && ptf.accuracy > ptf.zero)
		len++;
	return (len);
}

int			ft_flag_d(t_print ptf, int nb, char **str)
{
	int				len;
	int				i;
	unsigned int	unb;

	len = ft_convert_len_acc(ptf, nb);
	if (ft_realloc_adr_p(str, len, ptf.ret) == 0)
		return (0);
	i = ft_convert_signe(str, ptf, nb);
	i += (nb < 0) ? 1 : 0;
	unb = (nb < 0) ? (unsigned int)-nb : nb;
	if (!(ptf.tmp = ft_itoa_base(unb, 10)))
		return (0);
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	ft_memdel((void **)&ptf.tmp);
	return (len);
}
