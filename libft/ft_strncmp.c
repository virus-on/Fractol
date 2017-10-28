/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:52:33 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/22 11:52:37 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t					i;
	register unsigned char	*s1p;
	register unsigned char	*s2p;

	if (!n)
		return (0);
	i = 0;
	s1p = (unsigned char *)s1;
	s2p = (unsigned char *)s2;
	while (++i < n && *s1p == *s2p && *s1p && *s2p)
	{
		s1p++;
		s2p++;
	}
	return (*s1p - *s2p);
}
