/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:25:40 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 22:53:16 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_exit(char **line, char **str, int fd)
{
	if (**str)
		ft_free_str(str);
	if (fd >= 0)
	{
		ft_free_str(line);
		get_next_line(fd, 1);
	}
	ft_printf("fdf: Invalid map\n");
	exit(1);
}

char	*read_map(int fd, int *y)
{
	char	*line;
	char	*str;

	line = "\0";
	str = "\0";
	while (1)
	{
		line = get_next_line(fd, 0);
		if (line == NULL)
			break ;
		if (*line == '\n')
			ft_exit(&line, &str, fd);
		str = ft_strjoinfree(str, line);
		ft_free_str(&line);
		(*y)++;
	}
	if (!*str)
		ft_exit(&line, &str, -1);
	return (str);
}

void	create_matrix(t_list *map, char	*str, int y)
{
	char	**array;
	int		i;

	array = ft_split(str, '\n');
	ft_free_str(&str);
	map->matrix = ft_calloc(y + 1, sizeof(char **));
	i = 0;
	while (i < y)
	{
		map->matrix[i] = ft_split(array[i], ' ');
		i++;
	}
	map->matrix[i] = NULL;
	ft_free_array(&array);
	set_max(map, y);
}

void	parse_map(t_list	*map, char *file)
{
	int		fd;
	char	*str;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("fdf: %s: %s\n", strerror(errno), file);
		exit(1);
	}
	y = 0;
	str = read_map(fd, &y);
	close(fd);
	create_matrix(map, str, y);
}
