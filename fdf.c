/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 15:15:00 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/26 14:46:59 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_fdm	*mapa;

	if (argc != 2)
		ft_printf("Wrong number of arguments");
	else
	{
		if (init_mapa(&mapa, argv[1]))
			return (0);
		mlx_hook(mapa->win, 2, 3, press_key, mapa);
		mlx_loop_hook(mapa->mlx, draw_map, mapa);
		mlx_loop(mapa->mlx);
	}
	return (0);
}
