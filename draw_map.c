/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 10:46:24 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/22 19:08:07 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"
void	draw_line() //as cordenadas serao literais, por isso temos de usar o edge para fazer as linhas NAO E POSSIVEL: USAR O EDGE AO FAZER A TRANSFORMACAO PARA DST_X E DST_Y
{

}
void	draw_map(t_list	map, int x_max, int y_max)
{
	t_node	*point_a;
	t_node	*point_b;

	point_a = map.head;
	while(point_a != map.head->prev)
	{
		point_b = point_a->next;
		if (point_a->source_x < x_max)
			draw_line(point_a, point_b);
		while(point_a->source_x != point_b->source_x && point_b != map.head->prev)
			point_b = point_b->next;
		if (point_a->source_y < y_max || point_b != map.head->prev)
			draw_line(point_a, point_b);
		point_a->next;
	}
}
