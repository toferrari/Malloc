/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 10:57:20 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/31 12:00:00 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>
#include <string.h>
// #include "malloc.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <sys/mman.h>
uint32_t 	arc4random_uniform(uint32_t upper_bound);
// void 		*g_test;
//
// int main()
// {
// int i;
// char *addr;
//
// i = 0;
// while (i < 1024)
// {
// 	// if (!addr)
// 	// 	write(1,"null ", 5);
// 	// else
// 	// addr = (char*)malloc(1024);
// 	// addr[0] = 42;
// 	i++;
// }
// return (0);
// }


int			main(void)
{
	size_t	size;
	size_t	c;
	char	*tmp;
	char	*tmp2;
// ft_putendl("tptp");
	// void *test = malloc(32);
	// free(test);
	c = 0;
	 int i = 0;
	while (i < 1024)
	{
		// tmp = (char *)malloc(1024);
		// if (!tmp)
		// 	write(1,"null\n", 5);
		// else
		// 	tmp[0] = 42;
		i++;
	}

	// i = 0;
	// int o = arc4random_uniform(10000);
	// int b;
	// while (i < o)
	// {
	// 	b = arc4random_uniform(5000);
	// 	tmp = (char *)malloc(200);
	// 	tmp[0] = 42;
	// 	i++;
   // }
	 // show_alloc_mem();
	// tmp = (char *)malloc(1024);
	// tmp2 = (char *)malloc(1);
	// for (size_t i = 0; i < c; i++)
	// {
	// 	// printf("i = %d", i);
	// 	tmp = malloc(50);
	// 	if (arc4random_uniform(10) > 5)
	// 		free(tmp);
	// 	size = arc4random_uniform(100000);
	// 	tmp = malloc(size);
		// if (arc4random_uniform(10) > 5)
		// 	free(tmp);
 		// else
		// {
		// 	size = arc4random_uniform(10000);
		// 	tmp = realloc(tmp, size);
		// }

		// show_alloc_mem();
	// }
}
