/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_act.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:17:41 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/26 14:50:58 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		change_pos(int key_code, t_fdm *mapa)
{
	int		min;
	int		max;

	min = -2147483648;
	max = 2147483647;
	if (key_code == 0 && mapa->rig_lef != min)
		mapa->rig_lef -= 10;
	else if (key_code == 1 && mapa->top_bot != max)
		mapa->top_bot += 10;
	else if (key_code == 2 && mapa->rig_lef != max)
		mapa->rig_lef += 10;
	else if (key_code == 13 && mapa->top_bot != min)
		mapa->top_bot -= 10;
	return (0);
}

int		color_change(int key_code, t_fdm *mapa)
{
	if (key_code == 15)
		mapa->red += 5;
	else if (key_code == 5)
		mapa->green += 5;
	else if (key_code == 11)
		mapa->blue += 5;
	return (0);
}

int		psihodel(t_fdm *mapa)
{
	if (mapa->psihodel == 1)
		mapa->psihodel = 0;
	else
		mapa->psihodel = 1;
	return (0);
}

int		press_key(int key_code, t_fdm *mapa)
{
	if (key_code == 53)
	{
		ft_printf("Exit\n");
		exit(0);
	}
	else if (key_code == 27 && (mapa->zoom - 2) > 0)
		mapa->zoom -= 2;
	else if (key_code == 24 && (mapa->zoom + 2) < 170)
		mapa->zoom += 2;
	else if (key_code == 15 || key_code == 5 || key_code == 11 ||
		key_code == 14 || key_code == 10 || key_code == 9 || key_code == 3)
		color_change(key_code, mapa);
	else if (key_code == 123)
		mapa->angle -= 0.04;
	else if (key_code == 124)
		mapa->angle += 0.04;
	else if (key_code == 69 && ((mapa->z + 1) <= 20))
		mapa->z += 1;
	else if (key_code == 78 && ((mapa->z - 1) >= -20))
		mapa->z -= 1;
	else if (key_code == 0 || key_code == 1 || key_code == 2 || key_code == 13)
		change_pos(key_code, mapa);
	else if (key_code == 35)
		psihodel(mapa);
	return (0);
}
