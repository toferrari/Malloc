/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 16:22:38 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/28 21:37:54 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_convert_len_acc(t_print ptf, char *src)
{
	int len;

	len = ft_strlen(src);
	if (len == 0 && ptf.zero == 0)
		return (0);
	if (ptf.zero > len || (ptf.bool_acc != 1 && ptf.accuracy > len)
	|| (ptf.bool_acc == 1 && ptf.accuracy < len))
		len = (ptf.zero > ptf.accuracy) ? ptf.zero : ptf.accuracy;
	if ((size_t)ptf.zero > ft_strlen(src) && ptf.zero < ptf.accuracy)
		len = ptf.zero;
	return (len);
}

static void	ft_moin_on(char **str, t_print ptf, int len, char *src)
{
	if (ptf.accuracy > 0 && len > 0)
	{
		*str = ft_strnccat(*str, '0', ptf.accuracy - len);
		*str = ft_strncat(*str, src, ptf.accuracy);
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
	}
	else
	{
		*str = ft_strcat(*str, src);
		*str = ft_strnccat(*str, ' ', ptf.zero - len);
	}
}

static void	ft_moin_off(char **str, t_print ptf, int len, char *src)
{
	if (ptf.zero > 0 && len > 0 && len > ptf.accuracy && ptf.bool_acc == 1)
		*str = ft_strnccat(*str, ' ', ptf.zero - ptf.accuracy);
	else if (ptf.zero > 0 && len > 0)
		*str = ft_strnccat(*str, ' ', ptf.zero - (len));
	else
		*str = ft_strnccat(*str, ' ', ptf.zero);
	if (ptf.accuracy > 0 && len > 0 && ptf.bool_acc != 1)
	{
		*str = ft_strnccat(*str, '0', ptf.accuracy - len);
		*str = ft_strncat(*str, src, ptf.accuracy);
	}
	else if (ptf.bool_acc == 1)
		*str = ft_strncat(*str, src, ptf.accuracy);
	else
		*str = ft_strcat(*str, src);
}

int			ft_flag_str(t_print ptf, char *src, char **str)
{
	int	len;
	int	lenstr;
	int	i;

	i = 0;
	if (!src)
	{
		if (!(src = ft_strnew(6)))
			return (0);
		src = ft_strcpy(src, "(null)");
		i = 1;
	}
	lenstr = ft_strlen(src);
	len = ft_convert_len_acc(ptf, src);
	if (!ft_realloc_adr_p(str, len, ptf.ret))
		return (0);
	if (ptf.moins == 1)
		ft_moin_on(str, ptf, lenstr, src);
	else
		ft_moin_off(str, ptf, lenstr, src);
	if (i == 1)
		ft_memdel((void **)&src);
	return (len);
}
