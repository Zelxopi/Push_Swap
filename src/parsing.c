/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:34:37 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/07 11:26:06 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	is_char_digit(char *str)
{
	while (*str)
	{
		if (*str == '-')
			str++;
		if (*str >= '0' && *str <= '9')
			str++;
		else
			ft_error();
	}
}

void	check_twin(t_stack *l)
{
	t_node	*i;
	t_node	*j;

	i = l->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content == j->content)
				ft_error();
			j = j->next;
		}
		i = i->next;
	}
}

int	ft_atoi(const char *str)
{
	long long	nb;
	long long	negative;
	long long	i;

	nb = 0;
	negative = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			negative = -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i++] - '0');
		if ((nb * negative) > INT_MAX)
			ft_error();
		if ((nb * negative) < INT_MIN)
			ft_error();
	}
	return (nb * negative);
}

int	is_it_sorted(t_stack *l)
{
	t_node	*temp;

	temp = l->head->next;
	while (temp->next)
	{
		if (temp->content < temp->prev->content
			|| temp->content > temp->next->content)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	stack_sizer(t_stack *l)
{
	t_node	*temp;
	int		size;

	temp = l->head;
	size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return (size);
}
