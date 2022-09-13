/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:23:52 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/13 13:57:20 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	algo_starter(t_stack *a, t_stack *b)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	data->size = stack_sizer(a);
	if (data->size <= 3)
		sort3(a, b);
	else if (data->size <= 5)
		sort5(a, b);
	else
	{
		data->median = (data->size / 2);
		if (data->size < 500)
			data->buffer = (data->size * 0.15);
		if (data->size < 1000)
			data->buffer = 33;
		if (data->size >= 1000)
			data->buffer = (data->size * 0.03);
		if (data->buffer == 0)
			data->buffer = 1;
		data->bufferadd = data->buffer;
		send_to_b(a, b, data);
		back_to_a(a, b, data);
	}
	free(data);
}

void	sort3(t_stack *a, t_stack *b)
{
	int	top;
	int	middle;
	int	bottom;

	if (stack_sizer(a) == 2)
	{
		move(a, b, "sa");
		return ;
	}
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
		else
			move(a, b, "ra");
	}
	sort3(a, b);
	while (stack_sizer(b) != 0)
		move(a, b, "pa");
	if (!is_it_sorted(a))
		move(a, b, "sa");
}

void	send_to_b(t_stack *a, t_stack *b, t_data *data)
{
	while (a->head)
	{
		data->buffermin = data->median - data->buffer;
		data->buffermax = data->median + data->buffer;
		while (fit_in_buffer(a, data))
		{
			if (a->head->index >= data->buffermin
				&& a->head->index <= data->buffermax)
			{
				move(a, b, "pb");
				if (b->head->index < data->median)
					move(a, b, "rb");
			}
			else
				move(a, b, "ra");
		}
		data->buffer += data->bufferadd;
	}
}

void	back_to_a(t_stack *a, t_stack *b, t_data *data)
{
	while (b->head)
	{
		while (b->head->index != data->size)
			move(a, b, wheres_the_biggest(b, data));
		move(a, b, "pa");
		data->size--;
	}
}
