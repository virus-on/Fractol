/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 15:54:47 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/27 15:54:49 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*out;

	out = NULL;
	{
		if (lst)
		{
			out = f(lst);
			if (lst->next)
				out->next = ft_lstmap(lst->next, f);
		}
	}
	return (out);
}
