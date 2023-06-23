/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:08:00 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/23 18:47:06 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

float	ft_proj_x(int x, int y, long long z, int a)
{
	return(x + cos(a) + y * cos(a + 2) + z * cos(a - 2));
}

float	ft_proj_y(int x, int y, long long z, int a)
{
	return(x * sin(a) + y * sin(a + 2) + z * sin(a -2));
}

