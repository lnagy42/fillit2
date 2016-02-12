/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 16:55:24 by glangloi          #+#    #+#             */
/*   Updated: 2016/02/11 17:25:27 by glangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
}

void	ft_usage(void)
{
	ft_putstr("usage: fillit source_file\n");
}
