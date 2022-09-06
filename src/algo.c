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
		while(fit_in_buffer(a, data))
		{
			if (a->head->index >= data->buffermin 
				&& a->head->index <= data->buffermax)
				move(a, b, "pb");
			else
				move(a, b, "ra");
		}
		data->buffer *= 2;
	}
}

char	*wheres_the_biggest(t_stack *l)
{
	int	h = 0;
	int	t = 0;
	t_node	*temp = l->head;

	while (temp)
	{
		h++;
		temp = temp->next;
	}
	temp = l->tail;
	while (temp)
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
		{
			move(a, b, wheres_the_biggest(b));
		}
		move(a, b, "pa");
		data->size--;
	}
}