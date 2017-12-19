/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_signe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 11:46:31 by tferrari          #+#    #+#             */
/*   Updated: 2017/02/15 19:10:57 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_convert_signe(char **str, t_print ptf, int nb)
{
	if (ptf.space == 1 && nb >= 0 && ptf.plus != 1 && ptf.c != 'u')
		*str = ft_strcat(*str, " ");
	return (((ptf.plus == 1 || ptf.space == 1) && nb >= 0) ? 1 : 0);
}
