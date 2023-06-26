/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:25:40 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/26 22:24:46 by rimarque         ###   ########.fr       */
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
		printf("(%d, %d) (%2.f, %2.f)\n", element->src_x, element->src_y, element->dst_x, element->dst_y);
		element = element->next;
	}
}

void	set_limits(t_list *map)
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
	map->dst_width = point_a->dst_x - point_b->dst_x;
	map->dst_height = map->head->prev->dst_y - map->head->dst_y;
	//diferenca entre o y do 1 e ultimo pontos + 1 porque as coordenadas comecam em zero??
	//diferenca entre o x dos outros 2 cantos
	//printf("%2.f, %2.f\n", map->dst_width , map->dst_height);
}
t_node	*create_node(int x, int y, long long z, t_list map)
{
	t_node	*point;

	point = malloc(sizeof(t_node));
	if (!point)
		return(NULL);
	point->src_x = x;
	point->src_y = y;
	x = x * map.edge;
	y = y * map.edge;
	point->dst_x = ft_proj_x(x, y, z);
	point->dst_y = ft_proj_y(x, y, z);
	//printf("source x: %d, source y: %d, dst x: %.2f, dst y: %.2f\n", point->src_x, point->src_y, point->dst_x, point->dst_y);
	return(point);
}

//cria o mapa da esquerda para a direita
//map[y][x][0] --> na posicao 0 esta o conteudo de z
void	create_map(t_list *map, char ***matrix)
{
	t_node	*point;
	int	y;
	int x;

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
	//print_stack(*map);
	set_limits(map);
}
int	count_num(char *str)
{
	int count;

	count = 0;
	while(*str)
	{
		if(ft_isdigit(*str))
			count++;
		str++;
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
		y++;
	}
	close(fd);
	//ft_printf("str: %s\n", str);
	//ft_printf("y: %d\n", y);
	array = ft_calloc(y, sizeof(char *));
	array = ft_split(str, '\n');
	map->src_x_max = count_num(array[0]) - 1;
	map->src_y_max = y - 1;
	//ft_printf("y: %d\n", y);
	matrix = ft_calloc(y + 1, sizeof(char **));
	i = 0;
	while(i < y)
	{
		matrix[i] = ft_split(array[i], ' ');
		i++;
	}
	matrix[i] = NULL;
	//map[y][x] --> na posicao x esta o conteudo = z
	//print_matrix(matrix);
	create_map(map, matrix);
}

//CRIAR LISTA DE PONTOS
