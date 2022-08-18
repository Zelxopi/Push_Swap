/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:32:28 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/18 15:59:29 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *l)
{
	t_node	*temp = malloc(sizeof(t_node));
	t_node	*third = malloc(sizeof(t_node));

	third = l->head->next->next;
	temp = l->head->next;
	temp->next = l->head;
	temp->prev = NULL;
	l->head = temp;
	l->head->next->next = third;
	l->head->next->prev = l->head;
	l->head->next->next->prev = l->head->next;
}

void	ft_push(t_stack *src, t_stack *dest)
{
	int	elem;

	elem = popfront(src);
	dlist_add_front(dest, elem);
}

void	ft_rotate(t_stack *l)
{
	int	elem;

	elem = popfront(l);
	dlist_add_back(l, elem);
}

void	ft_reverse_rotate(t_stack *l)
{
	int	elem;

	elem = popback(l);
	dlist_add_front(l, elem);
}

void	move(t_stack *a, t_stack *b, char *move)
{
	if (ft_strcmp(move, "sa") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swap(a);
	if (ft_strcmp(move, "sb") == 0 || ft_strcmp(move, "ss") == 0)
		ft_swap(b);
	if (ft_strcmp(move, "pa") == 0)
		ft_push(a, b);
	if (ft_strcmp(move, "pb") == 0)
		ft_push(b, a);
	if (ft_strcmp(move, "ra") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(a);
	if (ft_strcmp(move, "rb") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(b);
	if (ft_strcmp(move, "rra") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_reverse_rotate(a);
	if (ft_strcmp(move, "rrb") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_reverse_rotate(b);
}	
