/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:31:34 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/22 12:31:36 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;

	if (!(copy = (char*)malloc((ft_strlen(s1) + 1) * sizeof(*s1))))
		return (NULL);
	ft_strcpy(copy, s1);
	return (copy);
}
