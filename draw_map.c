/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:46:24 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/26 23:42:59 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	put_pixel_img(t_data img, int x, int y, int color)
{
	char	*dst;

	dst = img.addr + (y * img.line_length + x * (img.bits_per_pixel / 8));
	*(unsigned int *) dst = color;

}
void	draw_line(t_node point_a, t_node point_b, t_data img) //as cordenadas serao literais, por isso temos de usar o edge para fazer as linhas NAO E POSSIVEL: USAR O EDGE AO FAZER A TRANSFORMACAO PARA DST_X E DST_Y
{
	float	diff_x;
	float	diff_y;
	float	step;
	float	x_step_size;
	float	y_step_size;
	float	x;
	float	y;

	diff_x = point_b.dst_x - point_a.dst_x;
	diff_y = point_b.dst_y - point_a.dst_y;

	printf("A:(%d, %d) (%f, %f); ", point_a.src_x, point_a.src_y, point_a.dst_x, point_a.dst_y);
	printf("B:(%d, %d) (%f, %f)\n", point_b.src_x, point_b.src_y, point_b.dst_x, point_b.dst_y);
	printf("diff x: %f, diff y: %f\n", diff_x, diff_y);
	if (diff_x >= diff_y) //step e igual a maior distancia
		step = diff_x;
	else
		step = diff_y;
	x_step_size = diff_x / step;
	y_step_size = diff_y / step;
	x = point_a.dst_x;
	y = point_a.dst_y;
	//printf("step: %f, x_init: %f, y_init: %f, x: %f, y: %f\n", step, x_init, y_init, x, y);
	int i = 0;
	while (i <= step)
	{
		put_pixel_img(img, x, y, COLOR);
		printf("x: %f, y: %f\n", x, y);
		x = x + x_step_size;
		y = y + y_step_size;
		i++;
	}
	//ft_put_pixel(img, x, y, COLOR);
}

void	draw_map(t_list map, t_data img)
{
	t_node	*point_a;
	t_node	*point_b;

	point_a = map.head;
	int count = 0;

	//while(point_a != map.head->prev)
	while(count++ < 100)
	{
		point_b = point_a->next;
		if (point_a->src_x < map.src_x_max)
		{
			//printf("HORIZONTAL: ");
			//printf("A:(%d, %d) (%2.f, %2.f); ", point_a->src_x, point_a->src_y, point_a->dst_x, point_a->dst_y);
			//printf("B:(%d, %d) (%2.f, %2.f)\n", point_b->src_x, point_b->src_y, point_b->dst_x, point_b->dst_y);
			draw_line(*point_a, *point_b, img);
		}
		while(point_a->src_x != point_b->src_x && point_b != map.head->prev)
			point_b = point_b->next;
		if (point_a->src_y < map.src_y_max || point_b != map.head->prev)
		{
			//printf("VERTICAL: ");
			//printf("A:(%d, %d) (%2.f, %2.f); ", point_a->src_x, point_a->src_y, point_a->dst_x, point_a->dst_y);
			//printf("B:(%d, %d) (%2.f, %2.f)\n", point_b->src_x, point_b->src_y, point_b->dst_x, point_b->dst_y);
			draw_line(*point_a, *point_b, img);
		}
		point_a = point_a->next;
		//printf("\n");
	}
}
