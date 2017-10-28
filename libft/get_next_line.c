/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaziuk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:52:05 by mpaziuk           #+#    #+#             */
/*   Updated: 2017/01/19 12:52:07 by mpaziuk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "stdio.h"

int				ft_extract_line(char *buff, char **line)
{
	int		i;
	char	*temp;

	i = ft_strclen(buff, '\n');
	if (*line)
	{
		temp = ft_strnew(ft_strlen(*line));
		ft_strcpy(temp, *line);
		free(*line);
		*line = ft_strnew(ft_strlen(temp) + i);
		ft_strcpy(*line, temp);
		*line += ft_strlen(temp);
		ft_strncpy(*line, buff, i);
		*line -= ft_strlen(temp);
		free(temp);
	}
	else
	{
		*line = ft_strnew(i);
		ft_strncpy(*line, buff, i);
	}
	return (1);
}

int				ft_get_line(char **buff, char **line)
{
	char	*b2;
	int		i;

	i = ft_strclen(*buff, '\n');
	ft_extract_line(*buff, line);
	if ((*buff)[i] == 0)
	{
		free(*buff);
		*buff = NULL;
		return (0);
	}
	if ((*buff)[i + 1] != 0 && (b2 = ft_strnew(BUFF_SIZE)) && (*buff += i + 1))
	{
		ft_strcpy(b2, *buff);
		*buff -= i + 1;
		free(*buff);
		*buff = b2;
	}
	else
	{
		free(*buff);
		*buff = NULL;
	}
	return (1);
}

int				get_next_line1(const int fd, char **line)
{
	char			*buff;
	static char		*old_buff = NULL;
	int				ret;
	int				i;

	i = 0;
	if (old_buff && ft_get_line(&old_buff, line))
		return (1);
	buff = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		i = ft_extract_line(buff, line);
		if (ft_strclen(buff, '\n') != BUFF_SIZE)
			break ;
		ft_bzero(buff, BUFF_SIZE);
	}
	if (ret == 0 && i == 0 && *line == NULL)
		return (0);
	i = ft_strclen(buff, '\n');
	if (i + 1 < BUFF_SIZE && i + 1 < (int)ft_strlen(buff)
		&& (old_buff = ft_strnew(BUFF_SIZE)))
	{
		ft_strcpy(old_buff, (buff += i + 1));
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	*line = NULL;
	return (get_next_line1(fd, line));
}
