/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 18:23:10 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/28 18:12:29 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

static int	ft_0_pourcent(char **str, char *format, int ret)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(format);
	if (ft_realloc_adr_p(str, len, ret) == 0)
		return (0);
	*str = ft_strcat_p(*str, format, ret);
	return (len);
}

static int	ft_parse(char *format, va_list *arg, int ret, char **str)
{
	int		i;
	int		nb;

	i = 0;
	if (*str == NULL)
		*str = ft_strnew(1);
	if (!ft_strchr(format, '%'))
		return (ret += ft_0_pourcent(str, format, ret));
	if (format[i] != '%')
	{
		if (ft_realloc_adr_p(str, i = ft_strclen(format, '%'), ret) == 0)
			return (0);
		*str = ft_strccat_p(*str, format, '%', ret);
		ret += i;
	}
	if (format[i + 1] && format[i] == '%')
	{
		format += i + 1;
		nb = ft_parse_flag(&format, arg, str, ret);
		ret = ft_parse(format, arg, ret + nb, str);
	}
	return (ret);
}

int			ft_printf(char *format, ...)
{
	va_list	arg;
	int		ret;
	char	*str;

	str = NULL;
	va_start(arg, format);
	ret = 0;
	ret = ft_parse(format, &arg, ret, &str);
	if (ret != -1)
		write(1, str, ret);
	va_end(arg);
	ft_memdel((void **)&str);
	return (ret);
}
