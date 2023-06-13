/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:03:59 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/31 18:38:58 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int	*stack;
	int	size;
}		t_stack;

void	validate_arguments(int argc, char **argv);

void	ft_error(char **arg, int argc);

int		check_duplicate(char **arg, int index);

t_stack	create_stack_a(int argc, char **argv);

t_stack	create_stack_b(t_stack stack_a);

int		check_num(char *str);

void	swap(t_stack stack, char c, int flag);

void	rotate(t_stack stack, char c, int flag);

void	reverse_rotate(t_stack stack, char c, int flag);

void	push(t_stack *src, t_stack *dest, char c);

void	reverse_rotate_rrr(t_stack stack_a, t_stack stack_b);

void	rotate_rr(t_stack stack_a, t_stack stack_b);

void	swap_ss(t_stack stack_a, t_stack stack_b);

void	sort(t_stack stack_a, t_stack stack_b);

void	radix(t_stack stack_a, t_stack stack_b);

#endif
