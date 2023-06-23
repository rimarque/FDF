/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rimarque <rimarque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 11:32:37 by rimarque          #+#    #+#             */
/*   Updated: 2023/06/23 19:23:48 by rimarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fdf.h"

void	create_stack(t_list *stack)
{
	stack->head = NULL;
	stack->edge = 10;
	stack->angle = 120;
	stack->size = 0;
}

void	insert_last(t_list *stack, t_node *new)
{
	static int	index = 0;
	t_node		*new;

	if (stack->head == NULL)
	{
		stack->head = new;
		new->next = stack->head;
		new->prev = stack->head;
	}
	else
	{
		stack->head->prev->next = new;
		new->prev = stack->head->prev;
		new->next = stack->head;
		stack->head->prev = new;
	}
	stack->size++;
}
void	free_stack(t_list *stack)
{
	t_node	*element;
	t_node	*temp;
	int		counter;

	if (stack->head == NULL)
		return ;
	element = stack->head;
	counter = 0;
	while (counter++ < stack->size)
	{
		temp = element;
		element = element->next;
		free(temp);
	}
	stack->head = NULL;
	stack->size = 0;
}*/
