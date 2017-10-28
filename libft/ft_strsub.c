/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:34:23 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/24 14:34:25 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_new;

	if (s)
	{
		if ((s_new = ft_strnew(len)))
		{
			ft_strncpy(s_new, s + start, len);
			return (s_new);
		}
	}
	return (NULL);
}
