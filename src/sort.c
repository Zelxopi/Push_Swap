/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:53:02 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/06 14:30:48 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_starter(t_stack *a, t_stack *b)
{
	t_data	*data = malloc(sizeof(t_data));
	data->size = stack_sizer(a);

	if (data->size <= 3)
	sort3(a, b);
	else if (data->size <= 5)
	sort5(a, b);
	else
	{
		data->median = (data->size / 2);
		data->buffer = (data->size * 0.1);
		if (data->buffer == 0)
		data->buffer = 1;
		yeet_to_b(a, b, data);
		back_to_a(a, b, data);
	}
}

int	fit_in_buffer(t_stack *l, t_data *data)
{
	t_node	*temp;

	temp = l->head;
	while (temp)
	{
		if (temp->index >= data->buffermin 
			&& temp->index <= data->buffermax)
			return (1);
		temp = temp->next;
	}
	return(0);
}

void	sort3(t_stack *a, t_stack *b)
{
	int	top;
	int	middle;
	int	bottom;

	while (!is_it_sorted(a))
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
	if (!is_it_sorted(a))
	move(a, b, "sa");
}