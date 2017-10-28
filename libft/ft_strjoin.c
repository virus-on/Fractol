/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:46:42 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/24 14:46:43 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*conact_s;

	if (s1 && s2)
	{
		if ((conact_s = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcpy(conact_s, s1);
			ft_strcpy(&conact_s[ft_strlen(s1)], s2);
			return (conact_s);
		}
	}
	return (NULL);
}
