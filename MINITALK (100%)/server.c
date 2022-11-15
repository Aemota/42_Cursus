/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albjimen <albjimen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 17:38:20 by albjimen          #+#    #+#             */
/*   Updated: 2022/11/08 20:32:06 by albjimen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig)
{
	static int	i = 7;
	static char	c = 0;

	if (sig == SIGUSR2)
		c = c | (1 << i);
	i--;
	if (i < 0)
	{
		if (c == '\0')
		{
			ft_printf("\n");
			i = 7;
			c = 0;
			return ;
		}
		ft_printf("%c", c);
		i = 7;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("PID: %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
}
