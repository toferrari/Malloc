/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:59:26 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/30 19:01:37 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern t_memory		g_mem;

void	free(void *ptr)
{
	t_mall	*tmp;

	pthread_mutex_init(&g_mutex, NULL);
	pthread_mutex_lock(&g_mutex);
	if (!ptr || !(tmp = found_it(ptr)))
		return ;
	if (tmp->len > SMALL && munmap(tmp->ptr, tmp->len) == -1)
		return ;
	tmp->use = 'n';
	tmp->len = 0;
	pthread_mutex_unlock(&g_mutex);
	pthread_mutex_destroy(&g_mutex);
}
