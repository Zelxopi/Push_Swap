/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:34:29 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/01 15:55:13 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_list(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		j;
	int		value;
	char	**args;

	check_twin(argv);
	i = 1;
	j = 0;
	while (argv[i] && i < argc)
	{
		args = ft_split(argv[i++], ' ');
		check_twin(args);
		while (args[j])
		{
			is_char_digit(args[j]);
			value = ft_atoi(args[j++]);
			if (value == 'f')
				ft_error("One of your value does not fit an int");
			dlist_add_back(stack_a, value);
			stack_a->size++;
		}
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stacks(&stack_a, &stack_b);
	if (argc < 2)
		ft_error("Not enough arguments");
	if (argc >= 2)
		create_list(argc, argv, &stack_a);
	index_init(&stack_a);
	index_from_smallest(&stack_a);
	view(stack_a);
	printf("\n/////moves/////\n");
	sort5(&stack_a, &stack_b);
	printf("\n-----post move-----\n");
	view(stack_a);
	return (0);
}
