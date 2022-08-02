/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrembla <mtrembla@student.42quebec>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:03:44 by mtrembla          #+#    #+#             */
/*   Updated: 2022/08/02 10:34:25 by mtrembla         ###   ########.fr       */
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

typedef struct s_data
{
	t_node	*head_a;
	t_node	*tail_a;
	t_node	*head_b;
	t_node	*tail_b;
	int		size;
} t_data;

#endif