/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:59:26 by tferrari          #+#    #+#             */
/*   Updated: 2017/11/06 18:12:32 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void	*g_stack[3];

void	free(void *ptr)
{
	t_mall	*tmp;

	if (!ptr)
		return ;
	tmp = found_it(ptr);
	if (tmp->len > SMALL && munmap(tmp->ptr, tmp->len) == -1)
		return ;
	tmp->use = 'n';
	tmp->len = 0;
}
