/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 13:18:31 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/23 13:18:32 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (ft_strlen(big) < ft_strlen(little))
		return (NULL);
	if (!*little)
		return ((char*)big);
	return (ft_strnstr(big, little, ft_strlen(big)));
}
