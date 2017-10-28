/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 15:23:15 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/21 15:25:02 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*s1;
	unsigned char	*s2;

	if (len)
	{
		s1 = (unsigned char*)dst;
		s2 = (unsigned char*)src;
		if (s2 < s1)
		{
			s1 += len;
			s2 += len;
			while (len--)
				*--s1 = *--s2;
		}
		else
		{
			while (len--)
				*s1++ = *s2++;
		}
	}
	return (dst);
}
