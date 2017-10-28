/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 12:13:17 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/27 12:13:19 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strclen(const char *s, char c)
{
	register int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}