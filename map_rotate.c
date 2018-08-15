/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:10:09 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/28 19:10:09 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

void	map_rotate(t_graf *tg1)
{
	int i;
	int j;

	j = 0;
	while (j < tg1->ny)
	{
		i = 0;
		while (i < tg1->nx)
		{
			if (j < tg1->ny - 1)
				line_draw(rotate_z(rotate_y(rotate_x(tg1->tp[j][i], tg1->angle,
			tg1->centre), tg1->angle1, tg1->centre), tg1->angle2, tg1->centre),
			rotate_z(rotate_y(rotate_x(tg1->tp[j + 1][i], tg1->angle,
			tg1->centre), tg1->angle1, tg1->centre), tg1->angle2,
			tg1->centre), tg1);
			if (i < tg1->nx - 1)
				line_draw(rotate_z(rotate_y(rotate_x(tg1->tp[j][i], tg1->angle,
			tg1->centre), tg1->angle1, tg1->centre), tg1->angle2, tg1->centre),
			rotate_z(rotate_y(rotate_x(tg1->tp[j][i + 1], tg1->angle,
			tg1->centre), tg1->angle1, tg1->centre), tg1->angle2,
			tg1->centre), tg1);
			i++;
		}
		j++;
	}
}

void	key_part3(int key, t_graf *tg1)
{
	double scale1;

	if (key == 87 || key == 91
		|| key == 86 || key == 88)
	{
		if (key == 91 || key == 87)
			tg1 = move_y(tg1, key);
		else
			tg1 = move_x(tg1, key);
		mlx_clear_window(tg1->mlx, tg1->win);
		map_rotate(tg1);
	}
	else if (key == 27 || key == 24)
	{
		scale1 = tg1->scale;
		if (key == 27)
			tg1->scale /= 1.25;
		else
			tg1->scale *= 1.25;
		ch_scale(tg1, scale1);
		mlx_clear_window(tg1->mlx, tg1->win);
		map_rotate(tg1);
		ch_scale_z1(tg1, scale1);
	}
}

int		handle_events(int key, t_graf *tg1)
{
	if (!key_part1(key, tg1))
	{
		if (!key_part2(key, tg1))
			key_part3(key, tg1);
	}
	if (key == 53)
		exit_x(tg1);
	return (0);
}

void	parse_incycle(t_graf *tg, t_list *tl, int j1, int x)
{
	int i1;

	i1 = 0;
	while (i1 < tg->nx)
	{
		tg->tp[j1][i1].x = i1;
		tg->tp[j1][i1].y = j1;
		tg->tp[j1][i1].z = (double)(ft_atoi(&(tl->content)[x]));
		tg->tp[j1][i1].color = 0x00FFFFFF;
		if (j1 == (int)(tg->ny / 2) && i1 == (int)(tg->nx / 2))
			tg->centre = tg->tp[j1][i1];
		x = skip_parse(tl, x);
		if (((char *)tl->content)[x] == ',')
		{
			x += 3;
			tg->tp[j1][i1].color = ft_atoi_base(&(tl->content)[x], 16);
			while (is_hex(((char *)tl->content)[x]))
				x++;
			while (((char *)tl->content)[x] == ' ')
				x++;
		}
		i1++;
	}
}

void	parse(t_graf *tg, t_list *tl)
{
	int j1;
	int x;

	j1 = 0;
	x = 0;
	tg->tp = (t_point **)malloc(sizeof(t_point *) * tg->ny);
	while (j1 < tg->ny)
	{
		tg->tp[j1] = (t_point *)malloc(sizeof(t_point) * tg->nx);
		parse_incycle(tg, tl, j1, x);
		x = 0;
		tl = tl->next;
		j1++;
	}
}
