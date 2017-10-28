/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:30:36 by mpaziuk           #+#    #+#             */
/*   Updated: 2016/11/25 15:30:38 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ret_pos(int n, int len)
{
	char	*out;

	if ((out = ft_strnew(len)))
	{
		while (len-- >= 0)
		{
			out[len] = '0' + (n % 10);
			n /= 10;
		}
		return (out);
	}
	return (NULL);
}

static char		*ret_neg(int n, int len)
{
	char	*out;

	if ((out = ft_strnew((len += 1))))
	{
		while ((len -= 1) != 0)
		{
			out[len] = '0' - (n % 10);
			n /= 10;
		}
		out[0] = '-';
		return (out);
	}
	return (NULL);
}

char			*ft_itoa(int n)
{
	int		len;

	len = ft_intpow(n);
	if (n >= 0)
		return (ret_pos(n, len));
	else
		return (ret_neg(n, len));
	return (NULL);
}
