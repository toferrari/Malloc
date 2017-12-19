/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_llu.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/24 18:10:41 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, uint64_t nb, uint64_t len)
{
	int intlen;

	intlen = ft_intlen_base64(nb, 10);
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - intlen);
	*str = ft_strcat(*str, ptf.tmp);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - intlen - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, uint64_t nb, uint64_t len)
{
	int intlen;

	intlen = ft_intlen_base64(nb, 10);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - intlen - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = ft_strnccat(*str, '0', ptf.accuracy - intlen);
	*str = ft_strcat(*str, ptf.tmp);
}

static int	ft_convert_len_acc_ll(t_print ptf, uint64_t nb)
{
	int64_t len;

	len = ft_intlen_base64(nb, 10);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.space == 1 || ptf.plus == 1)
		len++;
	return (len);
}

int			ft_flag_llu(t_print ptf, uint64_t nb, char **str)
{
	int64_t		len;
	int			i;

	len = ft_convert_len_acc_ll(ptf, nb);
	if (ft_realloc_adr_p(str, len, ptf.ret) == 0 ||
	!(ptf.tmp = ft_itoa_base64(nb, 10)))
		return (0);
	i = ft_convert_signe(str, ptf, nb);
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	ft_memdel((void **)&ptf.tmp);
	return (len);
}
