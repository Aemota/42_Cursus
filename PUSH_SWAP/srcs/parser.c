/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 18:36:12 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/31 18:44:46 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	validate_arguments(int argc, char **argv)
{
	int		i;
	int		len;
	char	**arg;

	if (argc < 2)
		exit(0);
	else if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
		arg = argv + 1;
	len = ft_charpp_len(arg);
	if (len < 1)
		exit(0);
	i = -1;
	while (++i < len)
	{
		if (!check_num(arg[i]))
			ft_error(arg, argc);
		if (ft_atoll(arg[i]) < -2147483648 || ft_atoll(arg[i]) > 2147483647)
			ft_error(arg, argc);
		if (check_duplicate(arg, i))
			ft_error(arg, argc);
	}
	if (argc == 2)
		ft_charpp_free(arg);
}

int	*normalizer(t_stack stack_a)
{
	int	*new_stack;
	int	cont;
	int	i;
	int	x;

	new_stack = ft_calloc(sizeof(int), stack_a.size + 1);
	x = 0;
	while (x < stack_a.size)
	{
		i = 0;
		cont = 0;
		while (i < stack_a.size)
		{
			if (stack_a.stack[x] > stack_a.stack[i])
				cont++;
			i++;
		}
		new_stack[x++] = cont;
	}
	free(stack_a.stack);
	return (new_stack);
}

t_stack	create_stack_a(int argc, char **argv)
{
	int		i;
	int		len;
	char	**arg;
	t_stack	stack_a;

	if (argc == 2)
		arg = ft_split(argv[1], ' ');
	else
		arg = argv + 1;
	len = ft_charpp_len(arg);
	stack_a.stack = ft_calloc(sizeof(int), len + 1);
	i = 0;
	while (i < len)
	{
		stack_a.stack[i] = ft_atoi(arg[i]);
		i++;
	}
	stack_a.size = len;
	stack_a.stack = normalizer(stack_a);
	if (argc == 2)
		ft_charpp_free(arg);
	return (stack_a);
}

t_stack	create_stack_b(t_stack stack_a)
{
	t_stack	stack_b;

	stack_b.size = 0;
	stack_b.stack = ft_calloc(sizeof(int), stack_a.size + 1);
	return (stack_b);
}
