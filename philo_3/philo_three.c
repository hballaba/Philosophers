/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:28:12 by hballaba          #+#    #+#             */
/*   Updated: 2020/12/09 19:28:14 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static t_kant		*ft_init_philosofers(t_dobray *table)
{
	t_kant	*kant;
	int		i;

	i = -1;
	if (!(kant = (t_kant*)malloc(sizeof(t_kant) * (table->num_phil))))
	{
		ft_error_malloc();
		return (NULL);
	}
	while (++i < table->num_phil)
	{
		kant[i].table = table;
		kant[i].lfork = i;
		kant[i].rfork = i + 1;
		if (i == table->num_phil - 1)
			kant[i].rfork = 0;
		kant[i].num = i;
		kant[i].eat_left = table->limit_eat;
		kant[i].last_eat = 0;
		kant[i].last_sleep = 0;
	}
	return (kant);
}

static int			ft_check_philo(t_dobray *table)
{
	char	*str;

	if (table->num_phil == 1)
	{
		str = ft_itoa(table->without_eat);
		write(1, "0 1 has taken a fork\n", 21);
		ft_mysleep(table->without_eat);
		write(1, str, ft_strlen(str));
		write(1, " 1 died\n", 8);
		free(str);
		str = NULL;
		return (1);
	}
	return (0);
}

static int			ft_init_forks(t_dobray *table)
{
	sem_unlink("write");
	sem_unlink("sem_forks");
	sem_unlink("dead");
	if ((table->forks = sem_open("sem_forks", O_CREAT, 0666, table->num_phil))\
	== SEM_FAILED)
		return (ft_error_malloc());
	if ((table->sem_write = sem_open("write", O_CREAT, 0666, 1)) == SEM_FAILED)
		return (ft_error_malloc());
	if ((table->sem_dead = sem_open("dead", O_CREAT, 0666, 1)) == SEM_FAILED)
		return (ft_error_malloc());
	table->pid = (pid_t*)malloc(sizeof(pid_t) * (table->num_phil));
	if (!table->pid)
		return (ft_error_malloc());
	table->thread = (pthread_t *)malloc(sizeof(pthread_t) * (table->num_phil));
	if (!table->pid)
		return (ft_error_malloc());
	sem_wait(table->sem_dead);
	return (0);
}

static int			ft_init_and_chek_arguments(int ar, char **av, \
					t_dobray *table)
{
	if (ar < 5 || ar > 6)
		return (ft_error());
	if ((table->num_phil = ft_atoi(av[1])) < 1)
		return (ft_error());
	if ((table->without_eat = ft_atoi(av[2])) < 1)
		return (ft_error());
	if ((table->eat = ft_atoi(av[3])) < 1)
		return (ft_error());
	if ((table->sleep = ft_atoi(av[4])) < 1)
		return (ft_error());
	if (ar == 6)
	{
		if ((table->limit_eat = ft_atoi(av[5])) < 1)
			return (ft_error());
	}
	else
		table->limit_eat = -1;
	table->flag_dead = 1;
	table->flag_write_dead = 1;
	table->start_time = ft_time();
	if ((ft_init_forks(table)) == 1)
		return (1);
	return (0);
}

int					main(int argc, char **argv)
{
	t_dobray	table;
	t_kant		*kant;

	if (ft_init_and_chek_arguments(argc, argv, &table))
		return (1);
	if (ft_check_philo(&table) == 1)
		return (1);
	if (!(kant = ft_init_philosofers(&table)))
		return (1);
	if (ft_start_fork(&table, kant, -1, -1))
	{
		ft_free(&table);
		return (1);
	}
	sem_post(kant->table->sem_write);
	sem_post(kant->table->sem_dead);
	return (0);
}
