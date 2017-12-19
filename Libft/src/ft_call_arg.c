/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_call_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 18:31:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/28 20:52:00 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static int	ft_call_arg2(va_list *arg, char **str, t_print ptf)
{
	if (ft_strchr("oO", ptf.c) && (ptf.l > 0 || ptf.j == 1 || ptf.z == 1))
		return (ft_flag_llo(ptf, (uint64_t)va_arg(*arg, long long), str));
	else if (ptf.h == 1 && ft_strchr("o", ptf.c))
		return (ft_flag_ho(ptf, (unsigned short)va_arg(*arg, int), str));
	else if (ft_strchr("o", ptf.c))
		return (ft_flag_octal(ptf, va_arg(*arg, unsigned int), str));
	else if (ft_strchr("xX", ptf.c) && (ptf.l > 0 || ptf.j == 1 || ptf.z == 1))
		return (ft_flag_llhexa(ptf, (uint64_t)va_arg(*arg, long long), str));
	else if (ft_strchr("p", ptf.c))
		return (ft_flag_p(ptf, (uint64_t)va_arg(*arg, long long), str));
	else if (ft_strchr("xX", ptf.c))
		return (ft_flag_hexa(ptf, va_arg(*arg, unsigned int), str));
	else if (ptf.c == 'S' || (ptf.c == 's' && ptf.l == 1))
		return (ft_flag_wstr(ptf, va_arg(*arg, wchar_t *), str));
	else if (ft_strchr("s", ptf.c))
		return (ft_flag_str(ptf, va_arg(*arg, char *), str));
	else if ((ptf.c == 'c' && ptf.l == 1) || ptf.c == 'C')
		return (ft_flag_wchr(ptf, (wchar_t)va_arg(*arg, int), str));
	else if (ptf.c == 'c')
		return (ft_flag_chr(ptf, (char)va_arg(*arg, int), str));
	else if (ptf.c == 'b')
		return (ft_flag_b(ptf, va_arg(*arg, unsigned int), str));
	return (0);
}

int			ft_call_arg(va_list *arg, char **str, t_print ptf, char **format)
{
	if (ft_strchr("DOU", ptf.c))
		ptf.l = 1;
	if (ptf.c == 0)
		return (ft_flag_c_null(ptf, format, str));
	else if (ptf.h == 2 && ft_strchr("o", ptf.c))
		return (ft_flag_hho(ptf, (unsigned char)va_arg(*arg, int), str));
	else if (ptf.h == 2 && ft_strchr("u", ptf.c))
		return (ft_flag_hhu(ptf, (unsigned char)va_arg(*arg, int), str));
	else if (ptf.h == 2 && ft_strchr("xX", ptf.c))
		return (ft_flag_hhx(ptf, (unsigned char)va_arg(*arg, int), str));
	else if ((ptf.l > 0 || ptf.j == 1 || ptf.z == 1) && ft_strchr("dDi", ptf.c))
		return (ft_flag_lld(ptf, (int64_t)va_arg(*arg, long long), str));
	else if (ft_strchr("dDi", ptf.c) && ptf.h == 2)
		return (ft_flag_hhd(ptf, (char)va_arg(*arg, int), str));
	else if (ft_strchr("dDi", ptf.c) && ptf.h == 1)
		return (ft_flag_hd(ptf, (short)va_arg(*arg, int), str));
	else if (ft_strchr("dDi", ptf.c))
		return (ft_flag_d(ptf, va_arg(*arg, int), str));
	else if ((ptf.l > 0 || ptf.j == 1 || ptf.z == 1) && ft_strchr("uU", ptf.c))
		return (ft_flag_llu(ptf, (uint64_t)va_arg(*arg, long long), str));
	else if (ft_strchr("Uu", ptf.c) || (ft_strchr("uU", ptf.c) && ptf.h == 1))
		return (ft_flag_u(ptf, va_arg(*arg, unsigned int), str));
	else if (ptf.c == '%')
		return (ft_flag_pourcent(ptf, str));
	return (ft_call_arg2(arg, str, ptf));
}
