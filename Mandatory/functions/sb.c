#include "../push_swap.h"

void sb(t_list **b)
{
	t_list *first;
	t_list *second;

	if(!b || !(*b)|| !(*b)->next)
		return ;
	first = *b;
	second = first->next;

	first->next= second->next;
	if(second->next)
		second->next->prev = first;
	
	second->prev= NULL;
	second->next= first;
	first->prev= second;
	*b = second; 
}