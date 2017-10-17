/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:17:59 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/17 13:22:15 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/mman.h>

# define TINY	128
# define SMALL	1024

typedef struct		s_mall
{
	void			*ptr;
	char			type;
	size_t			len;
	char			use;
	struct s_mall	*next;
}					t_mall;

size_t				page_tot;
void				*stack;

void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
void				*tiny();
void				*small();
int					init_mem(size_t malloc_size[2], size_t page_size);
int					init_stack(size_t len);
void				*new_page(size_t page_size);
void				*allocate(size_t size, size_t malloc_size[2]);

#endif
