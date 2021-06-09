/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:17:04 by hballaba          #+#    #+#             */
/*   Updated: 2020/12/08 16:17:08 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void		*died(void *kaaa)
{
	t_kant	*kant;
	int		i;
	int		diff;

	kant = kaaa;
	kant->last_eat = kant->start_time;
	i = kant->num;
	while (1)
	{
		diff = ft_time() - kant->last_eat;
		if (diff > kant->table->without_eat && kant->eat_left != 0)
		{
			kant->table->flag_dead = 0;
			ft_write_messege(kant, i, "died");
			pthread_mutex_lock(&kant->table->mutex_write);
			kant->table->flag_write_dead = 0;
			usleep(50);
			pthread_mutex_unlock(&kant->table->mutex_write);
			return (kaaa);
		}
		if (kant->table->flag_dead == 0 || kant->eat_left == 0)
			return (kaaa);
	}
	return (0);
}

static int		ft_left_eat(int i)
{
	if (i > 0)
		i--;
	return (i);
}

static void		*lunch(void *kaaa)
{
	t_kant	*kant;

	kant = (t_kant *)kaaa;
	pthread_create(&kant->pthread_died, NULL, died, kant);
	while (1)
	{
		pthread_mutex_lock(&kant->table->forks[kant->lfork]);
		ft_write_messege(kant, kant->num, "has taken a fork");
		pthread_mutex_lock(&kant->table->forks[kant->rfork]);
		ft_write_messege(kant, kant->num, "has taken a fork");
		ft_write_messege(kant, kant->num, "is eating");
		ft_mysleep(kant->table->eat);
		pthread_mutex_unlock(&kant->table->forks[kant->rfork]);
		kant->last_eat = ft_time();
		pthread_mutex_unlock(&kant->table->forks[kant->lfork]);
		if ((kant->eat_left = ft_left_eat(kant->eat_left)) == 0)
			break ;
		ft_write_messege(kant, kant->num, "is sleeping");
		ft_mysleep(kant->table->sleep);
		ft_write_messege(kant, kant->num, "is thinking");
		if (kant->table->flag_write_dead == 0 || kant->eat_left == 0)
			break ;
	}
	pthread_join(kant->pthread_died, NULL);
	return (kaaa);
}

int				ft_start_thread(t_dobray *table, t_kant *kant, int i)
{
	while (++i < table->num_phil)
	{
		kant[i].start_time = ft_time();
		if (i % 2 > 0)
		{
			if ((pthread_create(&table->thread[i], NULL, lunch, &kant[i])) < 0)
				return (1);
		}
	}
	ft_mysleep(10);
	i = -1;
	while (++i < table->num_phil)
	{
		if (i % 2 == 0)
		{
			if ((pthread_create(&table->thread[i], NULL, lunch, &kant[i])) < 0)
				return (1);
		}
	}
	i = -1;
	while (++i < table->num_phil)
		pthread_join(table->thread[i], NULL);
	return (0);
}
