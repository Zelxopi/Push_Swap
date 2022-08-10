/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:03:44 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/09 14:51:20 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
} t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

void	init_stacks(t_stack *a, t_stack *b);
void	dlist_add_back(t_stack *l, int elem);
void	dlist_add_front(t_stack *l, int elem);
void	view(t_stack l);
void	ft_is_char_digit(char *str);
void	ft_error(char *str);
void	check_twin(char **argv);

#endif