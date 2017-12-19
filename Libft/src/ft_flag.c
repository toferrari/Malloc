/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 13:40:04 by tferrari          #+#    #+#             */
/*   Updated: 2017/03/28 21:21:07 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_suite(char ***format, t_print *s_ptf, int i)
{
	int j;

	j = 0;
	while ((**format)[j] && ((**format)[j] == '#' || (**format)[j] == '-' ||
	(**format)[j] == '+' || (**format)[j] == ' '))
		j++;
	if (((**format)[j] == '0' && (**format)[i] != '.' && s_ptf->accuracy == 0 &&
	s_ptf->moins == 0))
	{
		s_ptf->accuracy = s_ptf->zero;
		s_ptf->zero = 0;
	}
}

void		ft_flag(char ***format, t_print *s_ptf)
{
	int i;

	i = 0;
	while ((**format)[i] && ((**format)[i] == '#' || (**format)[i] == '-' ||
	(**format)[i] == '+' || (**format)[i] == ' ' || ft_isdigit((**format)[i])))
	{
		if ((**format)[i] == '#')
			s_ptf->htag = 1;
		else if ((**format)[i] == '-')
			s_ptf->moins = 1;
		else if ((**format)[i] == '+')
			s_ptf->plus = 1;
		else if ((**format)[i] == ' ')
			s_ptf->space = 1;
		else if (ft_isdigit((**format)[i]) && (ft_isdigit((**format)[i - 1]) ||
		s_ptf->zero == 0))
			s_ptf->zero = s_ptf->zero * 10 + ((**format)[i] - '0');
		i++;
	}
	ft_suite(format, s_ptf, i);
	**format += i;
}
