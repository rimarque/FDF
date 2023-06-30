/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:25:40 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/30 22:43:39 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	print_stack(t_list	map)
{
	t_node *element;
	int	count;

	element = map.head;
	count = 0;
	while(count++ < map.size)
	{
		printf("(%d, %d) (%d, %d)\n", element->src_x, element->src_y, element->dst_x, element->dst_y);
		element = element->next;
	}
}

/*void	set_limits(t_list *map)
{
	t_node	*point_a;
	t_node	*point_b;

	point_a = map->head;
	point_b = map->head->prev;
	//printf("%d, %d\n", point_a->src_x, map->src_x_max);
	while(point_a->src_x != map->src_x_max)
	{
		//printf("%d, %d\n", point_a->src_x, map->src_x_max);
		point_a = point_a->next; //segfaults here
	}
	//printf("hello");
	while(point_b->src_x != 0)
		point_b = point_b->prev;
	//printf("A:(%d, %d) (%2.f, %2.f)\n", point_a->src_x, point_a->src_y, point_a->dst_x, point_a->dst_y);
	//printf("B:(%d, %d) (%2.f, %2.f)\n", point_b->src_x, point_b->src_y, point_b->dst_x, point_b->dst_y);
	map->dst_width = point_a->dst_x - point_b->dst_x + 1;
	map->dst_height = map->head->prev->dst_y - map->head->dst_y + 1; //tem problema aqui com o 10-70
	//diferenca entre o y do 1 e ultimo pontos + 1
	//diferenca entre o x dos outros 2 cantos
	//printf("%2.f, %2.f\n", map->dst_width , map->dst_height);
}*/
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
	//point->dst_x = ft_proj_x(x, y);
	point->dst_y = ft_proj_y(x, y, z);
	//IMPRIMIR MAPA SEM PROJECAO
	//point->dst_x = x;
	//point->dst_y = y;
	//printf("source x: %d, source y: %d, dst x: %.2f, dst y: %.2f\n", point->src_x, point->src_y, point->dst_x, point->dst_y);
	return(point);
}

//cria o mapa da esquerda para a direita
//map[y][x] --> na posicao 0 esta o conteudo de z
void	create_map(t_list *map, char ***matrix)
{
	t_node	*point;
	int	y;
	int x;
	float offset;

	set_z_scale(map, matrix);
	//ft_printf("colums: %d\n", colums);
	y = 0;
	//ft_printf("OI\n");
	while (y <= map->src_y_max)
	{
		//ft_printf("OI 1\n");
		x = 0;
		while(x <= map->src_x_max)
		{
			point = create_node(x, y, ft_atoi(matrix[y][x]), *map);
			insert_last(map, point);
			//set_limits(map); //segfatults here
			//ft_printf("OI 2\n");
			//ft_printf("(%d, %d, %d)\n", x, y, ft_atoi(map[y][x]));
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
	//print_stack(*map);
	set_limits(map);
}
int	count_num(char **array)
{
	int count;

	count = 0;
	while(array[count])
	{
		count++;
	}
	return(count);
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
		line = get_next_line(fd);
		if(line == NULL)
			break;
		str = ft_strjoinfree(str, line);
		ft_free_str(&line);
		y++;
	}
	close(fd);
	//ft_printf("str: %s\n", str);
	//ft_printf("y: %d\n", y);
	array = ft_calloc(y, sizeof(char *));
	array = ft_split(str, '\n');
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
	map->src_x_max = count_num(matrix[0]) - 1;
	set_scale(map);
	create_map(map, matrix);
}

//CRIAR LISTA DE PONTOS
