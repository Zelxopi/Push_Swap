/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 12:41:06 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/24 11:12:20 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *a, t_stack *b)
{
	a->size = 0;
	b->size = 0;
	a->head = NULL;
	a->tail = NULL;
	b->head = NULL;
	b->tail = NULL;
}

void	dlist_add_back(t_stack *l, int elem)
{
	t_node	*new = malloc(sizeof(t_node));

	if (!new)
		exit(0);
	new->content = elem;
	new->prev = l->tail;
	new->next = NULL;
	if (l->tail)
		l->tail->next = new;
	else
		l->head = new;
	l->tail = new;
}

void	dlist_add_front(t_stack *l, int elem)
{
	t_node	*new = malloc(sizeof(t_node));

	if (!new)
		exit(0);
	new->content = elem;
	new->next = l->head;
	new->prev = NULL;
	if (l->head)
		l->head->prev = new;
	else
		l->tail = new;
	l->head = new;
}

int	popfront(t_stack *l)
{
	int		val;
	t_node	*temp = l->head;

	if (!temp)
		return (-1);
	val = temp->content;
	l->head = temp->next;
	if (l->head)
		l->head->prev = NULL;
	else
		l->tail = NULL;
	free (temp);
	return (val);
}

int	popback(t_stack *l)
{
	int		val;
	t_node	*temp = l->tail;

	if (!temp)
		return (-1);
	val = temp->content;
	l->tail = temp->prev;
	if (l->tail)
		l->tail->next = NULL;
	else
		l->head = NULL;
	free (temp);
	return (val);
}
