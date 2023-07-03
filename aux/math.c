/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:08:00 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/03 22:53:51 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

float	get_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_proj_x(int x, int y, long long z)
{
	return (x * cos(ANGLE) + y * cos(ANGLE + 2) + z * cos(ANGLE - 2));
}

int	ft_proj_y(int x, int y, long long z)
{
	return (x * sin(ANGLE) + y * sin(ANGLE + 2) + z * sin(ANGLE - 2));
}

int	offset_x(t_list map)
{
	int	x;

	x = smallest_x(map);
	if (x < 0)
	{
		return (x * -1);
	}
	return (0);
}

int	offset_y(t_list map)
{
	int	y;

	y = smallest_y(map);
	if (y < 0)
	{
		return (y * -1);
	}
	return (0);
}
