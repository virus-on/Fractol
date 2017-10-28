/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:52:33 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/22 11:52:37 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	register size_t			i;
	register unsigned char	*s1p;
	register unsigned char	*s2p;

	if (n)
	{
		i = 0;
		s1p = (unsigned char *)s1;
		s2p = (unsigned char *)s2;
		while (i++ < n)
		{
			if (*s1p++ != *s2p++)
				return (*(s1p - 1) - *(s2p - 1));
		}
	}
	return (0);
}
