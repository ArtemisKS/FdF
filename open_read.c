/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupriia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:13:42 by akupriia          #+#    #+#             */
/*   Updated: 2018/02/28 19:13:43 by akupriia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "points.h"

static int		count_words(char *str, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0 && str[i] != c)
			count++;
		while (str[i] == c && str[i + 1])
		{
			if (str[i + 1] != c)
				count++;
			i++;
		}
		if (str[i])
			i++;
	}
	return (count);
}

t_list			*gnl_read(int *j, int *i, t_graf *tg)
{
	int		gnl;
	t_list	*t1;
	char	*line;
	t_list	*tl;

	line = NULL;
	tl = ft_lstnew(NULL, 0);
	while ((gnl = get_next_line(tg->fd, &line)) > 0)
	{
		t1 = ft_lstnew(line, ft_strlen(line) + 1);
		if (*j == 0)
			*i = count_words(line, ' ');
		ft_strdel(&line);
		ft_lstpush(&tl, t1);
		(*j)++;
	}
	ft_strdel(&line);
	if (gnl == -1)
	{
		perror("File is invalid");
		ft_memdel((void **)&tg);
		exit(1);
	}
	return (tl);
}

int				open_read(char *file, t_graf *tg)
{
	t_list	*tl;
	t_list	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if ((tg->fd = open(file, O_RDONLY)) == -1)
	{
		perror("File is invalid");
		ft_memdel((void **)&tg);
		exit(1);
	}
	tl = gnl_read(&j, &i, tg);
	close(tg->fd);
	tmp = tl;
	tl = tl->next;
	if (!(is_valid(tl)))
		return (0);
	tg->nx = i;
	tg->ny = j;
	calc_scale(tg);
	parse(tg, tl);
	free_list(tmp);
	return (1);
}

int				is_valid(t_list *tl)
{
	t_list	*tmp;
	int		i;

	tmp = tl;
	while (tl)
	{
		i = 0;
		while (((char *)tl->content)[i])
		{
			if (((char *)tl->content)[i] != ' '
			&& ((char *)tl->content)[i] != ','
			&& ((char *)tl->content)[i] != '-'
			&& (!(((char *)tl->content)[i] >= '0'
			&& ((char *)tl->content)[i] <= '9'))
			&& (!(is_hex(((char *)tl->content)[i])))
			&& ((char *)tl->content)[i] != 'x')
				return (0);
			i++;
		}
		tl = tl->next;
	}
	tl = tmp;
	return (1);
}
