/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:04:01 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/27 18:45:40 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack stack, char c, int flag)
{
	int	aux;

	if (flag == 1)
		ft_printf("s%c\n", c);
	if (stack.size > 1)
	{
		aux = stack.stack[0];
		stack.stack[0] = stack.stack[1];
		stack.stack[1] = aux;
	}
}

void	rotate(t_stack stack, char c, int flag)
{
	int	aux;
	int	i;

	if (flag == 1)
		ft_printf("r%c\n", c);
	if (stack.size > 1)
	{
		i = 0;
		aux = stack.stack[0];
		while (i < stack.size - 1)
		{
			stack.stack[i] = stack.stack[i + 1];
			i++;
		}
		stack.stack[i] = aux;
	}
}

void	reverse_rotate(t_stack stack, char c, int flag)
{
	int	aux;
	int	i;

	if (flag == 1)
		ft_printf("rr%c\n", c);
	if (stack.size > 1)
	{
		i = stack.size - 1;
		aux = stack.stack[stack.size - 1];
		while (i > 0)
		{
			stack.stack[i] = stack.stack[i - 1];
			i--;
		}
		stack.stack[i] = aux;
	}
}

void	push(t_stack *src, t_stack *dest, char c)
{
	int	aux;
	int	i;

	ft_printf("p%c\n", c);
	if (src->size > 0)
	{
		aux = src->stack[0];
		i = dest->size;
		while (i > 0)
		{
			dest->stack[i] = dest->stack[i - 1];
			i--;
		}
		dest->stack[i] = aux;
		i = 0;
		while (i < src->size - 1)
		{
			src->stack[i] = src->stack[i + 1];
			i++;
		}
		src->stack[i] = 0;
		src->size--;
		dest->size++;
	}
}
