/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:03:44 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/29 12:17:24 by mtrembla         ###   ########.fr       */
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
	int				index;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

//parsing
void	is_char_digit(char *str);
void	check_twin(char **argv);
//dlist
void	init_stacks(t_stack *a, t_stack *b);
void	dlist_add_back(t_stack *l, int elem);
void	dlist_add_front(t_stack *l, int elem);
int		popfront(t_stack *l);
int		popback(t_stack *l);
//moves
void	ft_swap(t_stack *l);
void	ft_push(t_stack *a, t_stack *b);
void	ft_rotate(t_stack *l);
void	ft_reverse_rotate(t_stack *l);
void	move(t_stack *a, t_stack *b, char *move);
//utils
void	view(t_stack l);
void	ft_error(char *str);
void	index_init(t_stack *l);
//sort
int	check_index(t_stack *l);
void	index_from_smallest(t_stack *l);
int	find_smallest(t_stack *l);
#endif
