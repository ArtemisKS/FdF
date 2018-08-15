/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 20:34:46 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/15 20:34:46 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

int			main(int ac, char **av)
{
	t_graf *tg;

	if (ac != 2)
		perror("usage: ./fdf input_file");
	else
	{
		tg = graf_init();
		if (!(open_read(av[1], tg)))
		{
			ft_putendl_fd("File is invalid", 2);
			exit(1);
		}
		tg->mlx = mlx_init();
		tg->win = mlx_new_window(tg->mlx, SCREEN, SCREEN, "fdf");
		make_central(tg);
		mult_zet(5, tg);
		map_rotate(tg);
		fill_tp_z(tg);
		mlx_hook(tg->win, 2, (1L << 0), handle_events, (void *)tg);
		mlx_hook(tg->win, 17, 1L << 17, exit_x, (void *)tg);
		mlx_loop(tg->mlx);
	}
	return (0);
}

void		fill_tp_z(t_graf *tg)
{
	int i1;
	int j1;

	j1 = 0;
	tg->tp_z = (t_point **)malloc(sizeof(t_point *) * tg->ny);
	while (j1 < tg->ny)
	{
		i1 = 0;
		tg->tp_z[j1] = (t_point *)malloc(sizeof(t_point) * tg->nx);
		while (i1 < tg->nx)
		{
			tg->tp_z[j1][i1].x = 0;
			tg->tp_z[j1][i1].y = 0;
			tg->tp_z[j1][i1].z = tg->tp[j1][i1].z;
			tg->tp_z[j1][i1].color = 0x00FFFFFF;
			i1++;
		}
		j1++;
	}
}

void		ch_scale_z1(t_graf *tg, double scale1)
{
	int i1;
	int j1;

	j1 = 0;
	while (j1 < tg->ny)
	{
		i1 = 0;
		while (i1 < tg->nx)
		{
			tg->tp_z[j1][i1].z *= tg->scale / scale1;
			i1++;
		}
		j1++;
	}
}

void		free_list(t_list *tl)
{
	t_list *tmp;

	while (tl)
	{
		tmp = tl;
		ft_memdel((void**)&tl->content);
		tl = tl->next;
		ft_memdel((void**)&tmp);
	}
}

t_graf		*graf_init(void)
{
	t_graf *tg;

	tg = (t_graf *)malloc(sizeof(t_graf));
	tg->win = NULL;
	tg->mlx = NULL;
	tg->tp = NULL;
	tg->tp_z = NULL;
	tg->angle = 0;
	tg->angle1 = 0;
	tg->angle2 = 0;
	return (tg);
}
