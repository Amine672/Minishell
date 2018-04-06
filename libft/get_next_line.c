/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akabbouc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 23:26:12 by akabbouc          #+#    #+#             */
/*   Updated: 2017/05/12 19:31:05 by akabbouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			read_line(int const fd, char **line, char **stock)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;

	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		*line = *stock;
		*stock = ft_strjoin(*line, buff);
		ft_strdel(line);
		*line = ft_strchr(*stock, '\n');
		return (1);
	}
	if (ret == 0)
	{
		*line = ft_strchr(*stock, '\n');
		if (*line == NULL)
		{
			*line = ft_strchr(*stock, '\0');
			if (!ft_strlen(*stock))
				return (0);
		}
		return (1);
	}
	return (-1);
}

t_stock		*create_list(int fd)
{
	t_stock		*stock;

	stock = (t_stock*)malloc(sizeof(t_stock));
	if (!stock)
		return (NULL);
	stock->fd = fd;
	stock->data = ft_strnew(0);
	stock->next = NULL;
	return (stock);
}

t_stock		*get_list(int fd)
{
	static t_stock	*stock = NULL;
	t_stock			*tmp;

	tmp = stock;
	if (fd < 0)
		return (0);
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (stock)
	{
		tmp = stock;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_list(fd);
		return (tmp->next);
	}
	else
		return (stock = create_list(fd));
}

void		*ft_realloc(void **ptr, size_t buff)
{
	void *freshptr;

	if ((freshptr = ft_memalloc(buff)) == NULL)
		return (NULL);
	if (*ptr)
	{
		ft_memcpy(freshptr, *ptr, buff);
		ft_memdel(ptr);
	}
	return (freshptr);
}

int			get_next_line(int const fd, char **line)
{
	char	c;
	int		i;

	i = -1;
	*line = NULL;
	while (read(fd, &c, 1) && c != 10)
	{
		(*line) = (char *)ft_realloc((void **)line, ++i + 1);
		(*line)[i] = c;
	}
	*line = (char *)ft_realloc((void **)line, ++i + 1);
	(*line)[i] = 0;
	return (1);
}
