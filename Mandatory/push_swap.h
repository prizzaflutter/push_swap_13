/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaskour <iaskour@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 08:11:02 by iaskour           #+#    #+#             */
/*   Updated: 2025/02/12 08:31:43 by iaskour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				content;
	int				index;
	int				cost;
	int				above_median;
	int				cheapest;
	struct s_list	*target_node;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
long	ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int a);
char	*ft_itoa(int n);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list *lst);
int		ft_putchar(char c, int fd);
void	ft_putstr(char *str, int fd);
char	**ft_split(char const *s, char c);
char	*ft_strnstr(const char *haystack,
			const char *needle, size_t start, size_t len);
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	ra(t_list **a, int print_t);
void	rb(t_list **b, int print_t);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a, int print_t);
void	rrb(t_list **b, int print_t);
void	rrr(t_list **a, t_list **b);
int		sort_3(t_list **stack_a);
void	sort_stack(t_list **stack_a, t_list **stack_b);
int		is_stack_a_sorted(t_list *stack_a);
void	set_index_median(t_list *stack);
void	set_target_a(t_list *a, t_list *b);
void	set_cost_a(t_list *a, t_list *b);
void	set_cheapest(t_list *a);
void	set_target_b(t_list *a, t_list *b);
void	move_a_to_b(t_list **stack_a, t_list **stack_b);
void	move_b_to_a(t_list **stack_a, t_list **stack_b);
t_list	*get_max_node(t_list *b);
void	set_cheapest(t_list *stack);
void	process_for_push (t_list **stack, t_list *top_node, char stack_name);

#endif