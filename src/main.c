/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:34:29 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/13 12:17:13 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	create_list(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		j;
	int		value;
	char	**args;

	i = 1;
	j = 0;
	while (argv[i] && i < argc)
	{
		args = ft_split(argv[i++], ' ');
		while (args[j])
		{
			is_char_digit(args[j]);
			value = ft_atoi(args[j++]);
			dlist_add_back(stack_a, value);
			stack_a->size++;
		}
		while (args[--j])
			free(args[j]);
		free(args);
		j = 0;
	}
	check_twin(stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stacks(&stack_a, &stack_b);
	if (argc < 2)
		ft_error();
	if (argc >= 2)
		create_list(argc, argv, &stack_a);
	index_init(&stack_a);
	indexisation(&stack_a);
	if (is_it_sorted(&stack_a))
	{
		printf("Already Sorted\n");
		ft_free(&stack_a);
	}
	algo_starter(&stack_a, &stack_b);
	if (!is_it_sorted(&stack_a))
		ft_error();
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
