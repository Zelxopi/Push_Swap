/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:03:44 by mtrembla          #+#    #+#             */
/*   Updated: 2022/09/07 11:34:32 by mtrembla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
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

typedef struct s_data
{
	int		median;
	int		buffer;
	int		bufferadd;
	int		buffermin;
	int		buffermax;
	int		size;
}	t_data;

//dlist
void	init_stacks(t_stack *a, t_stack *b);
void	dlist_add_back(t_stack *l, int elem);
void	dlist_add_front(t_stack *l, int elem);
int		popfront(t_stack *l);
int		popback(t_stack *l);
//parsing
void	is_char_digit(char *str);
void	check_twin(t_stack *l);
int		ft_atoi(const char *str);
int		is_it_sorted(t_stack *l);
int		stack_sizer(t_stack *l);
//moves
void	ft_swap(t_stack *l);
void	ft_push(t_stack *a, t_stack *b);
void	ft_rotate(t_stack *l);
void	ft_reverse_rotate(t_stack *l);
void	move(t_stack *a, t_stack *b, char *move);
//index
void	index_init(t_stack *l);
void	index_from_smallest(t_stack *l);
int		find_smallest(t_stack *l);
int		check_index(t_stack *l);
//algo
void	algo_starter(t_stack *a, t_stack *b);
void	sort3(t_stack *a, t_stack *b);
void	sort5(t_stack *a, t_stack *b);
void	send_to_b(t_stack *a, t_stack *b, t_data *data);
void	back_to_a(t_stack *a, t_stack *b, t_data *data);
//algo_utils
int		fit_in_buffer(t_stack *l, t_data *data);
char	*wheres_the_biggest(t_stack *l, t_data *data);
//utils
void	ft_error();
void	view(t_stack l);
void	ft_free(t_stack *l);

#endif
