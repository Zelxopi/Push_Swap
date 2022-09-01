/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 10:34:37 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/30 17:46:26 by mtrembla         ###   ########.fr       */
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
			ft_error("is not digit");
	}
}

void	check_twin(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				ft_error("Doublon");
			j++;
		}
		i++;
	}
}
