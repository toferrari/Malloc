/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_wchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/24 18:16:27 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

#include <locale.h>

static int	ft_convert_len_acc(t_print ptf, int len)
{
	if (ptf.zero == 0 && ptf.accuracy > 0 && ptf.bool_acc == 1)
		return (len);
	if ((ptf.zero > 1 || ptf.accuracy > 1))
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	return (len);
}

static void	ft_moin_off(char **str, t_print ptf, char *dest, int chr_len)
{
	if (ptf.zero > 0)
		*str = ft_strlnccat(*str, ' ', &ptf.ret,
		ptf.zero - ptf.accuracy - 1);
	else
		*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero);
	if (ptf.accuracy > 0 && ptf.chr && ptf.bool_acc == 0)
	{
		*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy - 1);
		*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
	}
	else
		*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
}

static void	ft_moin_on(char **str, t_print ptf, char *dest, int chr_len)
{
	if (ptf.accuracy > 0)
	{
		*str = ft_strlnccat(*str, '0', &ptf.ret, ptf.accuracy);
		*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
		*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - ptf.accuracy);
	}
	else
	{
		*str = ft_wchrcat(*str, dest, ptf.ret, chr_len);
		*str = ft_strlnccat(*str, ' ', &ptf.ret, ptf.zero - 1);
	}
}

int			ft_flag_wchr(t_print ptf, wchar_t c, char **str)
{
	int		chr_len;
	char	*dest;
	int		len;

	chr_len = ft_wchar_len(c);
	len = ft_convert_len_acc(ptf, chr_len);
	if (ft_realloc_adr_p(str, chr_len + len, ptf.ret) == 0 ||
	!(dest = ft_strnew(chr_len)))
		return (0);
	dest = ft_wchar_to_char(c, dest);
	ptf.chr = c;
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, dest, chr_len);
	else
		ft_moin_off(str, ptf, dest, chr_len);
	ft_memdel((void **)&dest);
	return (chr_len);
}
