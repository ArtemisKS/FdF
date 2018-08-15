/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:07:41 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/28 19:07:42 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

static void		move_x_pl(t_graf *tg1)
{
	int i;
	int j;

	j = 0;
	while (j < tg1->ny)
	{
		i = 0;
		while (i < tg1->nx)
			tg1->tp[j][i++].x += 20;
		j++;
	}
	tg1->centre.x += 20;
}

static void		move_x_min(t_graf *tg1)
{
	int i;
	int j;

	j = 0;
	while (j < tg1->ny)
	{
		i = 0;
		while (i < tg1->nx)
			tg1->tp[j][i++].x -= 20;
		j++;
	}
	tg1->centre.x -= 20;
}

t_graf			*move_x(t_graf *tg1, int key)
{
	if (key == 88)
		move_x_pl(tg1);
	else
		move_x_min(tg1);
	return (tg1);
}

void			mult_zet(int value, t_graf *tg1)
{
	int i;
	int j;

	j = 0;
	while (j < tg1->ny)
	{
		i = 0;
		while (i < tg1->nx)
		{
			if (tg1->tp[j][i].z)
				tg1->tp[j][i].z *= value;
			i++;
		}
		j++;
	}
}

t_graf			*mult_z(double value, t_graf *tg1)
{
	int i;
	int j;

	j = 0;
	while (j < tg1->ny)
	{
		i = 0;
		while (i < tg1->nx)
		{
			if (tg1->tp[j][i].z)
			{
				tg1->tp[j][i].z = tg1->tp_z[j][i].z * value;
				if (tg1->tp[j][i].z == 0)
					tg1->tp[j][i].z = 1;
			}
			i++;
		}
		j++;
	}
	return (tg1);
}
