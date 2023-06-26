/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:08:00 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/24 19:27:03 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

float	ft_proj_x(int x, int y, long long z)
{
	return(x + cos(ANGLE) + y * cos(ANGLE + 2) + z * cos(ANGLE - 2));
}

float	ft_proj_y(int x, int y, long long z)
{
	return(x * sin(ANGLE) + y * sin(ANGLE + 2) + z * sin(ANGLE -2));
}

