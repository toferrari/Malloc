/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:17:59 by tferrari          #+#    #+#             */
/*   Updated: 2017/10/06 17:34:13 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

#include <stdlib.h>

# define TINY		128
# define SMALL		512

typedef struct		s_mall
{
	void			*ptr;
	size_t			len_left;
	size_t			start_ptr;
	size_t			len;
	struct s_mal	*next;
}					t_mall;

t_mall				mall;

void				free(void *ptr);
void				*malloc(size_t size);
void				*realloc(void *ptr, size_t size);
void				show_alloc_mem();
void				*tiny(size_t len);
void				*small(size_t len);
void				*get_mem(size_t len);

#endif
