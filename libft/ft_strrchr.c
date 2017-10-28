/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:18:16 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/21 17:15:53 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	register unsigned char	*out;

	out = NULL;
	if (*s == c)
		out = (unsigned char*)s;
	while (*s++)
	{
		if (*s == c)
			out = (unsigned char*)s;
	}
	return ((char*)out);
}
