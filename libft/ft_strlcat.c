/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:53:49 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/22 14:53:51 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*dstp;
	char	*srcp;
	int		s;
	size_t	dlen;

	dstp = (char*)dst;
	srcp = (char*)src;
	s = size;
	while (s-- != 0 && *dstp != '\0')
		dstp++;
	dlen = dstp - dst;
	s = size - dlen;
	if (s == 0)
		return (dlen + ft_strlen(srcp));
	while (*srcp)
	{
		if (s-- > 1)
			*dstp++ = *srcp;
		srcp++;
	}
	*dstp = '\0';
	return (dlen + (srcp - src));
}
