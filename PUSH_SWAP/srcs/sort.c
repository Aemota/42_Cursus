/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:08:13 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/31 18:38:24 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*smallest_value(t_stack stack)
{
	int	i;
	int	*ret;

	i = 0;
	ret = ft_calloc(sizeof(int), 2);
	ret[0] = 2147483647;
	while (i < stack.size)
	{
		if (stack.stack[i] < ret[0])
		{
			ret[0] = stack.stack[i];
			ret[1] = i;
		}
		i++;
	}
	return (ret);
}

static void	sort_three(t_stack stack_a)
{
	if (stack_a.stack[0] < stack_a.stack[1]
		&& stack_a.stack[1] < stack_a.stack[2])
		return ;
	else if (stack_a.stack[0] < stack_a.stack[1]
		&& stack_a.stack[0] < stack_a.stack[2])
	{
		reverse_rotate(stack_a, 'a', 1);
		swap(stack_a, 'a', 1);
	}
	else if (stack_a.stack[0] > stack_a.stack[1]
		&& stack_a.stack[0] > stack_a.stack[2]
		&& stack_a.stack[1] > stack_a.stack[2])
	{
		swap(stack_a, 'a', 1);
		reverse_rotate(stack_a, 'a', 1);
	}
	else if (stack_a.stack[0] > stack_a.stack[1]
		&& stack_a.stack[0] > stack_a.stack[2])
		rotate(stack_a, 'a', 1);
	else if (stack_a.stack[1] > stack_a.stack[2])
		reverse_rotate(stack_a, 'a', 1);
	else
		swap(stack_a, 'a', 1);
}

static void	short_sort(t_stack stack_a, t_stack stack_b)
{
	int	*smallest;

	while (stack_a.size > 3)
	{
		smallest = smallest_value(stack_a);
		while (stack_a.stack[0] != smallest[0])
		{
			if (smallest[1] < (stack_a.size / 2))
				rotate(stack_a, 'a', 1);
			else
				reverse_rotate(stack_a, 'a', 1);
		}
		push(&stack_a, &stack_b, 'b');
		free(smallest);
	}
	sort_three(stack_a);
	while (stack_b.size > 0)
		push(&stack_b, &stack_a, 'a');
}

static int	check_sorted(t_stack stack_a)
{
	int	i;

	i = 0;
	while (i < stack_a.size - 1)
	{
		if (stack_a.stack[i] > stack_a.stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort(t_stack stack_a, t_stack stack_b)
{
	if (stack_a.size == 1 || check_sorted(stack_a))
		return ;
	else if (stack_a.size == 2 && stack_a.stack[0] > stack_a.stack[1])
		swap(stack_a, 'a', 1);
	else if (stack_a.size == 3)
		sort_three(stack_a);
	else if (stack_a.size < 6)
		short_sort(stack_a, stack_b);
	else
		radix(stack_a, stack_b);
}
