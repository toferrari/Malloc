/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrari <tferrari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 19:37:12 by tferrari          #+#    #+#             */
/*   Updated: 2016/11/22 18:30:54 by tferrari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlst;
	void	*ncontent;

	if (!(newlst = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (newlst != NULL && content != NULL)
	{
		ncontent = ft_memalloc(content_size);
		ft_memcpy(ncontent, content, content_size);
		newlst->content = ncontent;
		newlst->content_size = content_size;
	}
	else
	{
		newlst->content = NULL;
		newlst->content_size = 0;
	}
	newlst->next = NULL;
	return (newlst);
}
