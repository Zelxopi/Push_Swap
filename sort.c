/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:24:53 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/29 12:33:27 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_from_smallest(t_stack *l)
{
	t_node	*temp = l->head;
	int nbr = find_smallest(l);
	int	i = 1;
	
	while (check_index(l))
	{
		while (temp)
		{
			if (temp->content == nbr)
				temp->index = i++;
			temp = temp->next;
		}
		temp = l->head;
		nbr++;
	}
}

int find_smallest(t_stack *l)
{
	t_node	*temp = l->head;
	t_node  *smallest = l->head;
	
	while (temp)
	{
		if (temp->content < smallest->content)
			smallest = temp;
		temp = temp->next;
	}
	return(smallest->content);
}

int	check_index(t_stack *l)
{
	t_node	*temp = l->head;

	while (temp)
	{
		if (temp->index == -1)
			return (1);
		temp = temp->next;
	}
	return (0);
}