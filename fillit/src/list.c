/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 17:47:50 by glangloi          #+#    #+#             */
/*   Updated: 2016/02/12 12:08:58 by glangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

static int	ft_nb_tetri(char *buf)
{
	int		nb_tetr;
	int		i;

	i = 0;
	nb_tetr = 0;
	while (buf[i])
	{
		if (buf[i] == '#')
			nb_tetr++;
		i++;
	}
	if ((nb_tetr % 4) != 0)
		return (0);
	return (nb_tetr / 4);
}

int			ft_new_list(char *buf, t_tetr **start)
{
	int		nb;
	int		i;
	int		current;
	t_tetr	*tmp;

	if ((nb = ft_nb_tetri(buf)) == 0)
		return (0);
	tmp = ft_new_node(buf);
	*start = tmp;
	tmp->nbr = 'A';
	i = 1;
	current = 21;
	if (*buf == '\n')
		buf++;
	while (i < nb)
	{
		if (!(tmp->next = ft_new_node(buf + current)))
			return (0);
		tmp = tmp->next;
		tmp->nbr = 'A' + i;
		i++;
		current = current + 21;
	}
	tmp->next = NULL;
	return (nb);
}
