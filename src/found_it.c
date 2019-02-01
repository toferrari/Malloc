/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   found_it.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:01:56 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/16 17:26:48 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_mall	*found_it(void *ptr)
{
	int		i;
	t_mall	*tmp_mall;

	i = -1;
	if (!ptr)
		return (NULL);
	while (++i < 3)
	{
		tmp_mall = (t_mall*)(g_mem.stack[i]);
		while (tmp_mall->next && ptr != tmp_mall->ptr)
			tmp_mall = tmp_mall->next;
		if (ptr == tmp_mall->ptr)
			return (tmp_mall);
	}
	return (NULL);
}
