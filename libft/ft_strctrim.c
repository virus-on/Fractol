/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strctrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:48:32 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/24 15:48:33 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strctrim(char const *s, char c)
{
	unsigned int	bgn;
	unsigned int	end;
	char			*new_s;

	if (s)
	{
		if (!*s)
			return (ft_strnew(1));
		bgn = 0;
		end = ft_strlen(s) - 1;
		while ((s[bgn] == c) && bgn < end + 1)
			bgn++;
		while ((s[end] == c) && &s[end] != s)
			end--;
		if (bgn >= end || bgn == ft_strlen(s))
			return (ft_strnew(1));
		if ((new_s = ft_strnew(end - bgn + 1)))
		{
			ft_strncpy(new_s, s + bgn, end - bgn + 1);
			return (new_s);
		}
	}
	return (NULL);
}
