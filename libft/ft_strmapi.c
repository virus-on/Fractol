/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 14:09:40 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/24 14:09:41 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_s;
	unsigned int	i;

	if (f && s)
	{
		if ((new_s = ft_strnew(ft_strlen(s))))
		{
			ft_strcpy(new_s, s);
			i = 0;
			while (new_s[i])
			{
				new_s[i] = f(i, new_s[i]);
				i++;
			}
			return (new_s);
		}
	}
	return (NULL);
}
