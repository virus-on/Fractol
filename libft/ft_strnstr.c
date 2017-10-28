/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:55:50 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/22 15:55:51 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t			len_s;

	if (!*little)
		return ((char *)big);
	len_s = ft_strlen(little);
	while (ft_strncmp(big++, little, len_s) != 0)
	{
		if (len_s > --len)
			return (NULL);
	}
	big--;
	return ((char *)big);
}
