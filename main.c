/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:34:29 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/10 13:14:11 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void create_list(int argc, char **argv, t_stack *stack_a)
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
			ft_is_char_digit(args[j]);
			value = ft_atoi(args[j++]);
			dlist_add_back(stack_a, value);
		}
		j = 0;
	}
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	init_stacks(&stack_a, &stack_b);
	
	if (argc < 2)
		ft_error("Not enough arguments");
	if (argc >= 2)
		create_list(argc, argv, &stack_a);
	view(stack_a);
	return(0);
}