/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:34:29 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/10 12:27:00 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_list(int argc, char **argv, t_stack *stack_a)
{
	int			i;
	int			value;

	check_twin(argv);
	i = 0;
	while (argv[i++] && i < argc)
	{
		ft_is_char_digit(argv[i]);
		value = ft_atoi(argv[i]);
		dlist_add_back(stack_a, value);
	}
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	init_stacks(&stack_a, &stack_b);
	
	if (argc < 2)
		ft_error("Not enough arguments");
	if (argc > 2)
		create_list(argc, argv, &stack_a);
	if (argc == 2)
		return(0);
	view(stack_a);
	return(0);
}