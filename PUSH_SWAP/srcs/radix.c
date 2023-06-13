/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:53:55 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/30 20:37:21 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int max_num)
{
	int	i;
	int	cont;

	i = 1 << 30;
	cont = 0;
	while (i > 0)
	{
		if ((max_num & i) > 0)
			return (31 - cont);
		cont++;
		i >>= 1;
	}
	return (i);
}

void	radix(t_stack stack_a, t_stack stack_b)
{
	int	n_bits;
	int	i;
	int	nums;
	int	j;

	n_bits = get_max_bits(stack_a.size - 1);
	i = 0;
	while (i < n_bits)
	{
		nums = stack_a.size;
		j = 0;
		while (j < nums)
		{
			if (((stack_a.stack[0] ^ 2147483647) & (1 << i)) > 0)
				push(&stack_a, &stack_b, 'b');
			else
				rotate(stack_a, 'a', 1);
			j++;
		}
		while (stack_b.size > 0)
			push(&stack_b, &stack_a, 'a');
		i++;
	}
}
