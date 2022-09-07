/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:11:51 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/07 11:25:51 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error()
{
	ft_putstr_fd("Error\n", 2);
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

void	ft_free(t_stack *l)
{
	t_node	*temp;
	t_node	*next;

	next = l->head;
	while (next)
	{
		temp = next;
		next = next->next;
		free(temp);
	}
	l->head = NULL;
	l->tail = NULL;
}
