/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 13:34:56 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/09/06 13:35:46 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (ft_strncmp(s1, s2, ft_strlen(s1)));
	return (ft_strncmp(s1, s2, ft_strlen(s2)));
}
