/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:57:12 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/27 12:57:14 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	if ((new_list = (t_list*)malloc(sizeof(t_list))))
	{
		new_list->next = NULL;
		if (!content)
		{
			new_list->content = NULL;
			new_list->content_size = 0;
		}
		else
		{
			new_list->content = (void*)malloc(content_size);
			ft_memmove(new_list->content, content, content_size);
			new_list->content_size = content_size;
		}
		return (new_list);
	}
	return (NULL);
}
