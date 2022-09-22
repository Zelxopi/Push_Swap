/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:53:02 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/22 11:38:00 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
	return (0);
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
