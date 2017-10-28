/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:43:10 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/22 12:43:19 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*s;
	char	*s2;

	s = dst;
	s2 = (char *)src;
	while (len > 0 && *s2)
	{
		*s++ = *s2++;
		len--;
	}
	while (len > 0)
	{
		*s++ = '\0';
		len--;
	}
	return (dst);
}
