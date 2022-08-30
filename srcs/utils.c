/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:11:51 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/30 17:46:24 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

void	view(t_stack l)
{
	t_node	*aff;

	aff = l.head;
	while (aff)
	{
		printf("content:%d\n", aff->content);
		printf("index: %d\n", aff->index);
		aff = aff->next;
	}
}

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

int	is_it_sorted(t_stack *l)
{
	t_node	*temp;

	temp = l->head->next;
	while (temp->next)
	{
		if (temp->content < temp->prev->content
			|| temp->content > temp->next->content)
			return (1);
		temp = temp->next;
	}
	return (0);
}