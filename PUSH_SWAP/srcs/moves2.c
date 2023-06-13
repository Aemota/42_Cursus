/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:46:24 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/27 19:31:35 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ss(t_stack stack_a, t_stack stack_b)
{
	ft_printf("ss\n");
	swap(stack_a, 'a', 0);
	swap(stack_b, 'b', 0);
}

void	rotate_rr(t_stack stack_a, t_stack stack_b)
{
	ft_printf("rr\n");
	rotate(stack_a, 'a', 0);
	rotate(stack_b, 'b', 0);
}

void	reverse_rotate_rrr(t_stack stack_a, t_stack stack_b)
{
	ft_printf("rrr\n");
	reverse_rotate(stack_a, 'a', 0);
	reverse_rotate(stack_b, 'b', 0);
}
