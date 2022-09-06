/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:32:28 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/02 14:04:40 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack *l)
{
	int	one;
	int	two;

	one = popfront(l);
	two = popfront(l);
	dlist_add_front(l, one);
	dlist_add_front(l, two);
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
	if ((stack_sizer(a) > 1 && ft_strcmp(move, "sa") == 0)
		|| ft_strcmp(move, "ss") == 0)
		ft_swap(a);
	else if ((stack_sizer(b) > 1 && ft_strcmp(move, "sb") == 0)
		|| ft_strcmp(move, "ss") == 0)
		ft_swap(b);
	else if (ft_strcmp(move, "pa") == 0 && b->head)
		ft_push(b, a);
	else if (ft_strcmp(move, "pb") == 0 && a->head)
		ft_push(a, b);
	else if (ft_strcmp(move, "ra") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(a);
	else if (ft_strcmp(move, "rb") == 0 || ft_strcmp(move, "rr") == 0)
		ft_rotate(b);
	else if (ft_strcmp(move, "rra") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_reverse_rotate(a);
	else if (ft_strcmp(move, "rrb") == 0 || ft_strcmp(move, "rrr") == 0)
		ft_reverse_rotate(b);
	else
		return ;
	printf("%s\n", move);
}	
