/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:46:24 by rimarque          #+#    #+#             */
/*   Updated: 2023/07/01 19:44:45 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	put_pixel_img(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;

}
void	draw_line(t_node point_a, t_node point_b, t_data img)
{
	t_line	line;
	int		i;

	line.dif_x = point_b.dst_x - point_a.dst_x;
	line.dif_y = point_b.dst_y - point_a.dst_y;

	if (fabs(line.dif_x) >= fabs(line.dif_y))
		line.n_step = fabs(line.dif_x);
	else
		line.n_step = fabs(line.dif_y);
	line.x_step = line.dif_x / line.n_step;
	line.y_step = line.dif_y / line.n_step;
	line.x = point_a.dst_x;
	line.y = point_a.dst_y;
	i = 0;
	while (i <= line.n_step)
	{
		put_pixel_img(img, line.x, line.y, COLOR);
		line.x += line.x_step;
		line.y += line.y_step;
		i++;
	}
}

void	draw_map(t_list map, t_data img)
{
	t_node	*point_a;
	t_node	*point_b;

	point_a = map.head;
	while(point_a != map.head->prev)
	{
		point_b = point_a->next;
		if (point_a->src_x < map.src_x_max)
			draw_line(*point_a, *point_b, img);
		while(point_a->src_x != point_b->src_x && point_b != map.head->prev)
			point_b = point_b->next;
		if (point_a->src_y < map.src_y_max || point_b != map.head->prev)
			draw_line(*point_a, *point_b, img);
		point_a = point_a->next;
	}
}

