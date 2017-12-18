/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:57:20 by tferrari          #+#    #+#             */
/*   Updated: 2017/12/18 18:30:14 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <string.h>
#include "malloc.h"

uint32_t 	arc4random_uniform(uint32_t upper_bound);

int			main(void)
{
	size_t	size;
	size_t	c;
	void	*tmp;
// ft_putendl("tptp");
	void *test = malloc(32);
	free(test);
	c = (size_t)arc4random_uniform(100000);
	// printf("c = %zu\n", c);
	for (size_t i = 0; i < c; i++)
	{
		tmp = malloc(4096);
	// 	// if (arc4random_uniform(10) > 5)
	// 	// 	free(tmp);
	// 	size = arc4random_uniform(100000);
	// 	tmp = malloc(size);
	// 	if (arc4random_uniform(10) > 5)
	// 		free(tmp);
 	// 	else
	// 	{
	// 		size = arc4random_uniform(10000);
	// 		tmp = realloc(tmp, size);
	// 	}

	}
	// show_alloc_mem();
}
