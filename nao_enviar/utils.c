
#include "../includes/fdf.h"

void	print_stack(t_list	map)
{
	t_node *element;
	int	count;

	element = map.head;
	count = 0;
	while(count++ < map.size)
	{
		printf("(%d, %d) (%d, %d)\n", element->src_x, element->src_y, element->dst_x, element->dst_y);
		element = element->next;
	}
}
