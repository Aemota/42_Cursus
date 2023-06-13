/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:20:46 by albjimen          #+#    #+#             */
/*   Updated: 2023/05/31 18:44:27 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	validate_arguments(argc, argv);
	stack_a = create_stack_a(argc, argv);
	stack_b = create_stack_b(stack_a);
	sort(stack_a, stack_b);
	free(stack_a.stack);
	free(stack_b.stack);
}
