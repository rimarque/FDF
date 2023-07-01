/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:25:40 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/01 19:17:36 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	set_limits(t_list *map)
{
	map->dst_width = biggest_x(*map) + 1;
	map->dst_height =  biggest_y(*map) + 1;
}
t_node	*create_node(int x, int y, int z, t_list map)
{
	t_node	*point;

	point = malloc(sizeof(t_node));
	if (!point)
		return(NULL);
	point->src_x = x;
	point->src_y = y;
	x = x * map.edge;
	y = y * map.edge;
	z *= map.z_scale;
	point->dst_x = ft_proj_x(x, y, z);
	point->dst_y = ft_proj_y(x, y, z);
	return(point);
}

void	create_map(t_list *map, char ***matrix)
{
	t_node	*point;
	int	y;
	int x;
	float offset;

	set_z_scale(map, matrix);
	y = 0;
	while (y <= map->src_y_max)
	{
		x = 0;
		while(x <= map->src_x_max)
		{
			point = create_node(x, y, ft_atoi(matrix[y][x]), *map);
			insert_last(map, point);
			x++;
		}
		y++;
	}
	ft_free_matrix(&matrix);
	offset = calc_offset_x(*map);
	if(offset)
		increase_x(map, offset);
	offset = calc_offset_y(*map);
	if(offset)
		increase_y(map, offset);
	set_limits(map);
}

//matrix[y][x][0] --> na posicao 0 esta o conteudo de z
void	read_map(t_list	*map, char *file)
{
	int 	fd;
	char	*line;
	char	*str;
	size_t		y;
	char	**array;
	char	***matrix;
	size_t i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("fdf: %s: %s\n", strerror(errno), file);
		exit(1);
	}
	y = 0;
	line = "\0";
	str = "\0";
	while(1)
	{
		line = get_next_line(fd, 0);
		if(line == NULL)
			break;
		if (*line == '\n')
		{
			if (*str)
				ft_free_str(&str);
			ft_free_str(&line);
			get_next_line(fd, 1);
			ft_printf("fdf: Invalid map\n");
			exit(1);
		}
		str = ft_strjoinfree(str, line);
		ft_free_str(&line);
		y++;
	}
	close(fd);
	if (!*str)
	{
		ft_free_str(&line);
		if (*str)
			ft_free_str(&str);
		ft_printf("fdf: Invalid map\n");
		exit(1);
	}
	//ft_printf("str: %s\n", str);
	//ft_printf("y: %d\n", y);
	//array = ft_calloc(y, sizeof(char *));
	array = ft_split(str, '\n');
	//print_arr(array);
	ft_free_str(&str);
	//map->src_x_max = count_num(array[0]) - 1;
	map->src_y_max = y - 1;
	//ft_printf("y: %d, x: %d\n", map->src_y_max, map->src_x_max);
	//ft_printf("y: %d\n", y);
	matrix = ft_calloc(y + 1, sizeof(char **));
	i = 0;
	while(i < y)
	{
		matrix[i] = ft_split(array[i], ' ');
		i++;
	}
	matrix[i] = NULL;
	ft_free_array(&array);
	//map->src_x_max = count_num(matrix[0]) - 1;
	map->src_x_max = small_line(matrix, y) - 1;
	printf("y: %d, x: %d\n", map->src_y_max, map->src_x_max);
	if (map->src_x_max == -1)
	{
		ft_free_matrix(&matrix);
		ft_printf("fdf: Invalid map\n");
		exit(1);
	}
	set_scale(map);
	create_map(map, matrix);
}

//CRIAR LISTA DE PONTOS
