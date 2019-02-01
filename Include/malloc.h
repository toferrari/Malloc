/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:17:59 by tferrari          #+#    #+#             */
/*   Updated: 2019/01/31 11:51:40 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <sys/mman.h>
# include <pthread.h>

# define TINY	128
# define SMALL	1024
# define TAB(x)	(x < TINY) ? 0 : 1

typedef struct		s_mall
{
	void			*ptr;
	size_t			len;
	char			use;
	struct s_mall	*next;
}					t_mall;

typedef struct		s_memory
{
	size_t				page_tot[3];
	void				*stack[3];
}					t_memory;

t_memory			g_mem;
pthread_mutex_t		g_mutex;

void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				free(void *ptr);
void				show_alloc_mem();
void				*tiny();
void				*small();
int					init_mem(size_t malloc_size[2]);
int					init_stack(size_t len, size_t malloc_size[2]);
t_mall				*found_it(void *ptr);
void				*allocate(size_t size);
int					check_place(size_t size);
int					new_page(size_t size, size_t malloc_size[2],
					size_t page_size);
void				space(int type, size_t len);

#endif
