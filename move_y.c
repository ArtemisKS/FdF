/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_y.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:06:17 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/28 19:06:18 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

static void		move_y_min(t_graf *tg1)
{
	int i;
	int j;

	j = 0;
	while (j < tg1->ny)
	{
		i = 0;
		while (i < tg1->nx)
			tg1->tp[j][i++].y -= 20;
		j++;
	}
	tg1->centre.y -= 20;
}

static void		move_y_pl(t_graf *tg1)
{
	int i;
	int j;

	j = 0;
	while (j < tg1->ny)
	{
		i = 0;
		while (i < tg1->nx)
			tg1->tp[j][i++].y += 20;
		j++;
	}
	tg1->centre.y += 20;
}

t_graf			*move_y(t_graf *tg1, int key)
{
	if (key == 87)
		move_y_pl(tg1);
	else
		move_y_min(tg1);
	return (tg1);
}

int				key_part1(int key, t_graf *tg1)
{
	static double value = 1;

	if (key == 125 || key == 126)
	{
		if (key == 125)
			tg1->angle -= 0.1;
		else
			tg1->angle += 0.1;
		mlx_clear_window(tg1->mlx, tg1->win);
		map_rotate(tg1);
		return (1);
	}
	else if (key == 13 || key == 1)
	{
		if (key == 13)
			value += 0.125;
		else
			value -= 0.125;
		mlx_clear_window(tg1->mlx, tg1->win);
		tg1 = mult_z(value, tg1);
		map_rotate(tg1);
		return (1);
	}
	return (0);
}

int				key_part2(int key, t_graf *tg1)
{
	if (key == 123 || key == 124)
	{
		if (key == 123)
			tg1->angle1 -= 0.1;
		else
			tg1->angle1 += 0.1;
		mlx_clear_window(tg1->mlx, tg1->win);
		map_rotate(tg1);
		return (1);
	}
	else if (key == 0 || key == 2)
	{
		if (key == 0)
			tg1->angle2 -= 0.1;
		else
			tg1->angle2 += 0.1;
		mlx_clear_window(tg1->mlx, tg1->win);
		map_rotate(tg1);
		return (1);
	}
	return (0);
}
