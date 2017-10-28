/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:11:04 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/24 16:11:05 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strsplc(const char *s, int c)
{
	register size_t	i;

	if (s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (*s)
		{
			if (*s != c)
				i++;
			while (*s != c && *s)
				s++;
			while (*s == c && *s)
				s++;
		}
		return (i);
	}
	return (0);
}

char	*ft_nxtent(const char *s, char c, int i)
{
	if (s)
	{
		if (i == 0 && *s && *s != c)
			return ((char*)s);
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
		if (!*s)
			return (NULL);
	}
	return ((char *)s);
}

char	**ft_defret(const char *s, char c)
{
	char	**str;

	str = (char**)malloc(sizeof(char*) * 2);
	*str++ = ft_strctrim(s, c);
	*str = NULL;
	return (str - 1);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;

	if (s)
	{
		i = ft_strsplc(s, c);
		if (i == 1)
			return (ft_defret(s, c));
		if ((str = (char**)malloc(sizeof(char*) * (i + 1))))
		{
			i = 0;
			while ((s = ft_nxtent(s, c, i)))
			{
				*str = ft_strnew(ft_strclen(s, c));
				ft_strncpy(*str++, s, ft_strclen(s, c));
				i++;
			}
			*str = NULL;
			return (str - i);
		}
	}
	return (NULL);
}
