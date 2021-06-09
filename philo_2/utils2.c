/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:16:33 by hballaba          #+#    #+#             */
/*   Updated: 2020/12/08 16:16:35 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

long int	ft_time(void)
{
	struct timeval	time;
	long int		current_time;

	gettimeofday(&time, NULL);
	current_time = (long int)(time.tv_sec * 1000 + time.tv_usec * 0.001);
	return (current_time);
}

int			ft_mysleep(long int time_sleep)
{
	long int start_time;
	long int diff;

	start_time = ft_time();
	diff = ft_time() - start_time;
	while (diff < time_sleep)
	{
		diff = ft_time() - start_time;
		usleep(50);
	}
	return (0);
}

int			ft_error(void)
{
	ft_putstr_fd("Invalid argument\n", 2);
	return (1);
}

int			ft_error_malloc(void)
{
	ft_putstr_fd("Error malloc or initialization\n", 2);
	return (1);
}

void		ft_free(t_dobray *table)
{
	if (table->thread)
	{
		free(table->thread);
		table->thread = NULL;
	}
	sem_close(table->sem_write);
	sem_close(table->forks);
}
