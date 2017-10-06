/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:15:56 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/06 18:28:16 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "malloc.h"

extern t_mall	mall

void	*malloc(size_t size)
{
	void	*ptr;
	size_t	page_size;

	page_size = getpagesize();

	if (!mall)
		get_mem()
	ptr = NULL;
	return (ptr);
}

int main() {

	return 0;
}
