/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:18:16 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/21 13:18:19 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dstp;
	unsigned char		*srcp;

	dstp = (unsigned char*)dst;
	srcp = (unsigned char*)src;
	while (n)
	{
		*dstp++ = *srcp++;
		n--;
	}
	return (dst);
}
