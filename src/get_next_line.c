/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggeordi <ggeordi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 14:30:20 by ggeordi           #+#    #+#             */
/*   Updated: 2019/11/26 20:44:13 by ggeordi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	write_to_line(int fd, char **mem, char **line)
{
	size_t	len;
	char	*tmp;

	len = 0;
	while (mem[fd][len] != '\n' && mem[fd][len] != '\0')
		len++;
	if ((*line = ft_strnew(len + 1)) == NULL)
		return (-1);
	ft_strncpy(*line, mem[fd], len);
	(*line)[len] = '\0';
	tmp = ft_strsubfree(mem[fd], len + 1, ft_strlen(&(mem[fd][len])));
	if (tmp == NULL)
		return (-1);
	else
		mem[fd] = tmp;
	return (1);
}

static char	*create_mem(const int fd, char *buf, int *ret)
{
	char	*str;

	*ret = read(fd, buf, BUFF_SIZE);
	if (*ret < 0)
		return (NULL);
	buf[*ret] = '\0';
	if ((str = ft_strdup(buf)) == NULL)
		return (NULL);
	return (str);
}

static int	read_from_file(const int fd, char **mem)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	ret = 1;
	if (!mem[fd])
	{
		mem[fd] = create_mem(fd, buf, &ret);
		if (mem[fd] == NULL)
			return (-1);
	}
	while (ft_strchr(mem[fd], '\n') == NULL && ret > 0)
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		if ((tmp = ft_strjoinfree(mem[fd], buf)) == NULL)
		{
			ft_strdel(&(mem[fd]));
			return (-1);
		}
		else
			mem[fd] = tmp;
	}
	return (ret);
}

int			get_next_line(const int fd, char **line)
{
	static char	*mem[256];
	int			ret;

	if (fd < 0 || read(fd, NULL, 0) < 0 || line == NULL || BUFF_SIZE < 1)
		return (-1);
	if (mem[fd] != NULL && ft_strchr(mem[fd], '\n'))
		return (write_to_line(fd, mem, line));
	ret = read_from_file(fd, mem);
	if (ret < 0)
		return (-1);
	if (mem[fd][0] == '\0' && ret == 0)
	{
		ft_strdel(&(mem[fd]));
		return (0);
	}
	return (write_to_line(fd, mem, line));
}
