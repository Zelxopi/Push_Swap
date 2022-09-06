/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 12:23:52 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/06 14:31:56 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	yeet_to_b(t_stack *a, t_stack *b, t_data *data)
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

char	*wheres_the_biggest(t_stack *l, t_data *data)
{
	int		h;
	int		t;
	t_node	*temp;

	h = 0;
	t = 0;
	temp = l->head;
	while (temp->index != data->size)
	{
		h++;
		temp = temp->next;
	}
	temp = l->tail;
	while (temp->index != data->size)
	{
		t++;
		temp = temp->prev;
	}
	if (h <= t)
		return ("rb");
	else
		return ("rrb");
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
