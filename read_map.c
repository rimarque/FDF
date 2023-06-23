/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:25:40 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/23 19:24:04 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	print_map(char **map)
{
	int y;
	y = 0;
	while(map[y])
	{
		ft_putstr_fd(map[y], 1);
		write(1, "\n", 1);
		y++;
	}
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
	point->dst_x = ft_proj_x(x, y, z, map.angle);
	point->dst_y = ft_proj_y(x, y, z, map.angle);
	//printf("source x: %d, source y: %d, dst x: %.2f, dst y: %.2f\n", point->src_x, point->src_y, point->dst_x, point->dst_y);
	return(point);
}

//cria o mapa da esquerda para a direita
//map[y][x][0] --> na posicao 0 esta o conteudo de z
void	create_map(t_list *map, char ***map3D, int lines, int colums)
{
	t_node	*point;
	int	y;
	int x;

	//ft_printf("colums: %d\n", colums);
	y = 0;
	//ft_printf("OI\n");
	while (y < lines)
	{
		//ft_printf("OI 1\n");
		x = 0;
		while(x < colums)
		{
			point = create_node(x, y, ft_atoi(map3D[y][x]), *map);
			insert_last(map, point);
			//ft_printf("OI 2\n");
			//ft_printf("(%d, %d, %d)\n", x, y, ft_atoi(map[y][x]));
			x++;
		}
		y++;
	}
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
void	read_map(t_list	*map, char *file)
{
	int 	fd;
	char	*str;
	//char	***map;
	size_t		y;
	char	**map2D;
	char	***map3D;
	//map[y][x][0] --> na posicao 0 esta o conteudo de z
	char	*buff;
	size_t i;
	int x;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("fdf: %s: %s\n", strerror(errno), file);
		exit(1);
	}
	y = 0;
	str = "\0";
	buff = "\0";
	while(1)
	{
		str = get_next_line(fd);
		if(str == NULL)
			break;
		buff = ft_strjoinfree(buff, str);
		y++;
	}
	//ft_printf("buff: %s\n", buff);
	//ft_printf("y: %d\n", y);
	map2D = ft_calloc(y, sizeof(char *));
	map2D = ft_split(buff, '\n');
	x = count_num(map2D[0]);
	//ft_printf("x: %d\n", x);
	map3D = ft_calloc(y, sizeof(char **));
	i = 0;
	while(i < y)
	{
		map3D[i] = ft_split(map2D[i], ' ');
		i++;
	}
	//map[y][x] --> na posicao x esta o conteudo = z
	/*i = 0;
	while(i < y)
	{
		print_map(map3D[i++]);
		//write(1, "\n", 1);
	}*/
	create_map(map, map3D, y, x);
}

//CRIAR LISTA DE PONTOS
