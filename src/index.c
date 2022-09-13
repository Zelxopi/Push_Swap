/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:24:53 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/13 12:16:54 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	index_init(t_stack *l)
{
	t_node	*temp;

	temp = l->head;
	while (temp)
	{
		temp->index = -1;
		temp = temp->next;
	}
}

void indexisation(t_stack *l)
{
	t_node	*temp = l->head;
	t_node	*smallest;
	int 	i;

	i = 1;
	while (check_index(l))
	{
		while (temp->index != -1)
			temp = temp->next;
		smallest = temp;
		while (temp)
		{
			if (temp->index == -1 && temp->content < smallest->content)
				smallest = temp;
			temp = temp->next;
		}
		smallest->index = i++;
		temp = l->head;
	}
}

int	check_index(t_stack *l)
{
	t_node	*temp;

	temp = l->head;
	while (temp)
	{
		if (temp->index == -1)
			return (1);
		temp = temp->next;
	}
	return (0);
}
