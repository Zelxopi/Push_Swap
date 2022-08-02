/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:34:29 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/02 10:34:29 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(0);
}

int	ft_is_char_digit(char *str)
{
	while(*str)
	{
		if (*str >= '0' && *str <= '9')
			str++;
		else
		ft_error("is not digit");
	}
	return(0);
}

void	ft_createlist(int argc, char **argv)
{
	int	i;
	t_node *stack_a;
	t_node *temp;
	t_node	*head_a;

	i = 0;
	temp = NULL;
	while(argv[i++] && i < argc)
	{
		ft_is_char_digit(argv[i]);
		t_node *stack_a = malloc(sizeof(t_node));
		stack_a->content = ft_atoi(argv[i]);
		stack_a->next = NULL;
		stack_a->prev = NULL;
		if (temp)
		{
			stack_a->prev = temp;
			temp->next = stack_a;
		}
		else
			head_a = stack_a;
		temp = stack_a;
		stack_a = stack_a->next;
	}
	stack_a = head_a;
	 while(stack_a)
	{
	 	printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Not enough arguments");
	if (argc > 2)
		ft_createlist(argc, argv);
	if (argc == 2)
		return(0);
	return(0);
}