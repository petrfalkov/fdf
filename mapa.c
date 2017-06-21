/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichubare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:14:08 by ichubare          #+#    #+#             */
/*   Updated: 2017/02/26 14:43:10 by ichubare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	psihodel_col(t_fdm *mapa)
{
	static int		col;

	col = 0;
	if (mapa->blue >= 255 || mapa->red >= 255 || mapa->green >= 255)
		col = 0;
	mapa->blue += col++;
	mapa->green += col++;
	mapa->red += col++;
}

void	norm(t_fdm *mapa)
{
	if (mapa->blue >= 255)
		mapa->blue = 50;
	if (mapa->red >= 255)
		mapa->red = 50;
	if (mapa->green >= 255)
		mapa->green = 50;
}

void	make_matrix(t_fdm *mapa)
{
	int		i;
	int		len;
	char	**temp;
	int		j;

	i = 0;
	len = 0;
	mapa->matrix = (int**)malloc(sizeof(int*) * mapa->rows);
	while (i < mapa->rows)
	{
		j = 0;
		len = 0;
		temp = ft_strsplit(mapa->map[i], ' ');
		while (temp[len])
			len++;
		mapa->matrix[i] = (int*)malloc(sizeof(int) * len);
		while (temp[j])
		{
			mapa->matrix[i][j] = ft_atoi(temp[j]);
			j++;
		}
		free(temp);
		i++;
	}
	mapa->columns = len;
}

char	**take_map(char *argv, t_fdm *mapa)
{
	char	**map;
	int		i;
	int		fd;

	i = 0;
	map = (char**)malloc(sizeof(char*) * 1000);
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &map[i]) == 1)
		i++;
	map[i] = NULL;
	close(fd);
	if (i > 80)
		mapa->rows = i - 1;
	else
		mapa->rows = i;
	return (map);
}

int		init_mapa(t_fdm **mapa, char *argv)
{
	*mapa = (t_fdm*)malloc(sizeof(t_fdm));
	(*mapa)->map = take_map(argv, *mapa);
	make_matrix(*mapa);
	(*mapa)->green = 3;
	(*mapa)->blue = 32;
	(*mapa)->red = 144;
	(*mapa)->zoom = 30;
	(*mapa)->angle = 0.1;
	(*mapa)->z = 3;
	(*mapa)->top_bot = 1080 / 2;
	(*mapa)->rig_lef = 1920 / 2;
	if (!((*mapa)->mlx = mlx_init()))
		return (1);
	(*mapa)->win = mlx_new_window((*mapa)->mlx, 1920, 1080, "fdf");
	(*mapa)->next = NULL;
	return (0);
}
