#include "../push_swap.h"

void sa(t_list **a)
{
	t_list *first;
	t_list *second;

	if(!a || !(*a)|| !(*a)->next)
		return ;
	first = *a;
	second = first->next;

	first->next= second->next;
	if(second->next)
		second->next->prev = first;
	
	second->prev= NULL;
	second->next= first;
	first->prev= second;
	*a = second; 
	ft_putstr("sa\n", 1);
}