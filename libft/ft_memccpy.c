/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:18:16 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/21 14:01:10 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int		i;
	unsigned char		*dstp;
	unsigned char		*srcp;

	i = 0;
	dstp = (unsigned char*)dst;
	srcp = (unsigned char*)src;
	while (i < n)
	{
		if ((*dstp++ = *srcp++) == (unsigned char)c)
			return (dstp);
		i++;
	}
	return (NULL);
}
