/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:53:52 by glangloi          #+#    #+#             */
/*   Updated: 2016/02/11 17:26:47 by glangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

int		main(int ac, char **av)
{
	t_tetr	*start;
	int		nb;

	start = NULL;
	if (ac == 2)
	{
		if ((nb = ft_get_tetr(av[1], &start)) == -1)
		{
			ft_error();
			ft_free_list(start);
			return (0);
		}
		nb = ft_size_map(nb);
		ft_solve(nb, start);
	}
	else
		ft_usage();
}
