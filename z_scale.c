/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_scale.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:45:30 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/30 19:20:42 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

float	get_max(float a, float b)
{
	if (a > b)
		return(a);
	return(b);
}

int	smallest_z(t_list map, char	***matrix)
{
	int	y;
	int	x;
	int	result;

	y = 0;
	result = ft_atoi(matrix[0][0]);
	while (y <= map.src_y_max)
	{
		x = 0;
		while(x <= map.src_x_max)
		{
			if(result > ft_atoi(matrix[y][x]))
				result = ft_atoi(matrix[y][x]);
			x++;
		}
		y++;
	}
	return (result);
}
int	biggest_z(t_list map, char	***matrix)
{
	int	y;
	int	x;
	int	result;

	y = 0;
	result = ft_atoi(matrix[0][0]);
	while (y <= map.src_y_max)
	{
		x = 0;
		while(x <= map.src_x_max)
		{
			if(result < ft_atoi(matrix[y][x]))
				result = ft_atoi(matrix[y][x]);
			x++;
		}
		y++;
	}
	return (result);
}

//get_range -> zmax - zmin;
void	set_z_scale(t_list *map, char ***matrix)
{
	int	z_range;

	map->z_scale = 1;
	z_range = biggest_z(*map, matrix) - smallest_z(*map, matrix);
	//printf("big: %d, small: %d, z range: %d\n", biggest_z(*map, matrix), smallest_z(*map, matrix), z_range);
	if (z_range)
		map->z_scale = 0.1 * get_max(map->src_x_max, map->src_y_max) * map->edge / z_range;
	if (map->z_scale < 1)
		map->z_scale = 1;
}
void	set_scale(t_list *map)
{
	//float	img_max;
	float	img_hyp;
	float	scale;

	//img_max = get_max(map->dst_width, map->dst_height);
	scale = 0.4 * 1920;
	img_hyp = sqrtf(powf(map->src_x_max + 1, 2) + powf(map->src_y_max + 1, 2)); //teorema de pitagoras
	map->edge = scale / img_hyp;
}



