#include "push_swap.h"
#include <stdio.h>

int main ()
{
	t_list *first_node;
	first_node = ft_lstnew("idriss");
	printf("first node is : %s\n", first_node->content);
	printf("next => %p\n", first_node->next);
	printf("prev => %p\n", first_node->prev);
    
}