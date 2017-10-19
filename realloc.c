/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 14:41:36 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/19 14:59:19 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

extern void		*stack[3];
extern size_t	page_tot[3];

void	*realloc(void *ptr, size_t size)
{
	// t_mall	*tmp_mall;
	//
	// tmp_mall = (t_mall*)stack;
	// while (tmp_mall && ptr != tmp_mall->ptr)
	// 	tmp_mall = tmp_mall->next;
	// if (tmp_mall)
	// 	return (NULL);
	// if ((tmp_mall->len < TINY && size < TINY) || ((size >= TINY && size < SMALL)
	// && (tmp_mall->len >= TINY && tmp_mall->len < SMALL)))
	// 	return (ptr);
	return (NULL);
}
