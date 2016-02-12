/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:35:00 by glangloi          #+#    #+#             */
/*   Updated: 2016/02/12 12:43:35 by glangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		ft_check_size_tetr(char **tetr)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr[i][j] == '#')
				size++;
			j++;
		}
		i++;
	}
	if (size == 4)
		return (1);
	return (0);
}

int		ft_check_next2(char **tetr)
{
	int		i;
	int		j;
	int		valid;

	i = 3;
	valid = 0;
	while (i >= 0)
	{
		j = 3;
		while (j >= 0)
		{
			if (tetr[i][j] == '#')
			{
				if (j > 0 && tetr[i][j - 1] == '#')
					valid++;
				if (i > 0 && tetr[i - 1][j] == '#')
					valid++;
			}
			j--;
		}
		i--;
	}
	return (valid);
}

##
 ##

int		ft_check_next(char **tetr)
{
	int		i;
	int		j;
	int		valid;

	i = 0;
	valid = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (tetr[i][j] == '#')
			{
				if (j < 3 && tetr[i][j + 1] == '#')
					valid++;
				if (i < 3 && tetr[i + 1][j] == '#')
					valid++;
			}
			j++;
		}
		i++;
	}
	if ((valid = valid + ft_check_next2(tetr)) < 5)
		return (0);
	return (1);
}

int		ft_check_symbols(char *buf, int size)
{
	while (size > 0)
	{
		size--;
		if ((buf[size] != '.') && (buf[size] != '#') && (buf[size] != '\n'))
			return (0);
	}
	return (1);
}

int		ft_check_size(char *buf, int size)
{
	int		squ_x;
	int		squ_y;

	while (size >= 0)
	{
		size--;
		squ_y = 0;
		while (squ_y < 4)
		{
			squ_x = 0;
			if (buf[size] != '\n')
				return (0);
			while (squ_x < 4)
			{
				size--;
				if (size < 0 || buf[size] == '\n')
					return (0);
				squ_x++;
			}
			squ_y++;
			size--;
		}
	}
	return (1);
}
