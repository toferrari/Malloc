/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_lld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:18:50 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/24 17:59:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_moin_on(char **str, t_print ptf, int64_t nb, int64_t len)
{
	uint64_t	unb;
	int64_t		intlen;

	unb = (nb < 0) ? (uint64_t)-nb : nb;
	intlen = ft_intlen_base64(unb, 10);
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	if (ptf.accuracy > 0)
		*str = ft_strnccat(*str, '0', ptf.accuracy - intlen);
	*str = ft_strcat(*str, ptf.tmp);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - intlen - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
}

static void	ft_moin_off(char **str, t_print ptf, int64_t nb, int64_t len)
{
	uint64_t	unb;
	int64_t		intlen;

	unb = (nb < 0) ? (uint64_t)-nb : nb;
	intlen = ft_intlen_base64(unb, 10);
	if (ptf.accuracy == 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - intlen - len);
	else
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy - len);
	*str = (nb < 0) ? ft_strcat(*str, "-") : *str;
	*str = ft_strnccat(*str, '0', ptf.accuracy - intlen);
	*str = ft_strcat(*str, ptf.tmp);
}

static int	ft_convert_len_acc_ll(t_print ptf, int64_t nb)
{
	int64_t len;

	len = ft_intlen_64(nb);
	if (ptf.zero > len || ptf.accuracy > len)
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if (ptf.space == 1 || ptf.plus == 1)
		len++;
	return (len);
}

int			ft_flag_lld(t_print ptf, int64_t nb, char **str)
{
	int64_t		len;
	int			i;
	uint64_t	unb;

	unb = (nb < 0) ? (uint64_t)-nb : nb;
	len = ft_convert_len_acc_ll(ptf, nb);
	if (ft_realloc_adr_p(str, len, ptf.ret) == 0 ||
	!(ptf.tmp = ft_itoa_base64(unb, 10)))
		return (0);
	i = ft_convert_signe(str, ptf, nb);
	i += (nb < 0) ? 1 : 0;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, nb, i);
	else
		ft_moin_off(str, ptf, nb, i);
	ft_memdel((void **)&ptf.tmp);
	return (len);
}
