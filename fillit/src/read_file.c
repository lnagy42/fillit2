/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:16:13 by glangloi          #+#    #+#             */
/*   Updated: 2016/02/11 17:50:01 by glangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

static int	ft_fill_tetri(t_tetr **start, char *buf)
{
	t_tetr	*current;
	char	*tmp;
	int		nb;
	int		i;

	tmp = buf;
	if ((nb = ft_new_list(tmp, start)) == 0)
		return (-1);
	i = nb;
	current = *start;
	while (i)
	{
		if (!ft_check_next(current->tetr)
				|| !ft_check_size_tetr(current->tetr))
			return (-1);
		current = current->next;
		i--;
	}
	return (nb);
}

static int	ft_file_opener(char *source, char *buf)
{
	int		fd;
	int		ret;

	if ((fd = open(source, O_RDONLY)) == -1)
		return (-1);
	ret = read(fd, buf, BUF_SIZE);
	if (ret > 545 || ret == -1)
		return (-1);
	buf[ret] = '\0';
	if (close(fd) == -1)
		return (-1);
	return (ret);
}

static int	ft_init_buf(char *source, char *buf)
{
	int		size;

	if ((size = ft_file_opener(source, buf)) == -1)
		return (-1);
	if (!ft_check_symbols(buf, size))
		return (-1);
	if (!ft_check_size(buf, size))
		return (-1);
	return (size);
}

int			ft_get__tetr(char *source, t_tetr **start)
{
	int		size;
	char	*buf;
	int		nb;

	buf = (char *)ft_memalloc(BUF_SIZE);
	if ((size = ft_init_buf(source, buf)) == -1)
	{
		ft_memdel((void **)&buf);
		return (-1);
	}
	if ((nb = ft_fill_tetri(start, buf)) == -1)
	{
		ft_memdel((void **)&buf);
		return (-1);
	}
	ft_memdel((void **)&buf);
	return (nb);
}
