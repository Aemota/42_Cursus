/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:48:42 by albjimen          #+#    #+#             */
/*   Updated: 2022/11/08 21:04:51 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	messenger(int pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i > -1)
	{
		bit = (c >> i) & 1;
		if (bit == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(50);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc != 3 || ft_isdigit_str(argv[1]) == 0)
		return (ft_putstr_fd("error de argumentos\n", 2), 1);
	i = 0;
	while (i <= ft_strlen(argv[2]))
		messenger(ft_atoi(argv[1]), argv[2][i++]);
	return (0);
}
