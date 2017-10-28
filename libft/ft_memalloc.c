/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:32:47 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/24 13:32:49 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*alloc_mem;

	if ((alloc_mem = (void *)malloc(size)))
	{
		ft_memset(alloc_mem, 0, size);
		return (alloc_mem);
	}
	return (NULL);
}
