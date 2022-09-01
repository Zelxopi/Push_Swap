/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:53:02 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/01 15:57:15 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort3(t_stack *a, t_stack *b)
{
	int	top;
	int	middle;
	int	bottom;

	while (is_it_sorted(a) != 0)
	{	
		top = a->head->content;
		middle = a->head->next->content;
		bottom = a->head->next->next->content;
		
		if (top > middle && bottom > top)
		move(a, b, "sa");
		else if (middle > top && middle > bottom)
		move(a, b, "rra");
		else if (top > middle && top > bottom)
		move(a, b, "ra");
	}
}

void	sort5(t_stack *a, t_stack *b)
{
	while (stack_sizer(a) != 3)
	{
		if (a->head->index == 1 || a->head->index == 2)
			move(a, b, "pb");
		else move(a, b, "ra");
	}
	sort3(a, b);
	while (stack_sizer(b) != 0)
	move(a, b, "pa");
	if (is_it_sorted(a) != 0)
	move(a, b, "sa");
}