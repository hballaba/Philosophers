/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:17:20 by hballaba          #+#    #+#             */
/*   Updated: 2020/12/08 16:17:23 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H

# define PHILO_ONE_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct		s_dobray
{
	int				num_phil;
	int				without_eat;
	int				sleep;
	int				eat;
	int				limit_eat;
	int				flag_dead;
	int				flag_write_dead;
	long int		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	mutex_died;
	pthread_mutex_t	mutex_write;
	pthread_mutex_t	mutex_time;
	pthread_t		*thread;
}					t_dobray;

typedef struct		s_kant
{
	int				num;
	t_dobray		*table;
	long int		last_eat;
	int				eat_left;
	int				last_sleep;
	long int		start_time;
	int				lfork;
	int				rfork;
	int				num_thread;
	pthread_t		pthread_died;
}					t_kant;

int					ft_start_thread(t_dobray *table, t_kant *kant, int i);
char				*ft_itoa(int n);
size_t				ft_strlen(const char *str);
int					ft_atoi(char *str);
void				ft_putstr_fd(char *s, int fd);
long int			ft_time(void);
int					ft_mysleep(long int time_sleep);
int					ft_error(void);
int					ft_error_malloc(void);
void				ft_write_messege(t_kant *kant, int i, char *str);
void				ft_free(t_dobray *table);

#endif
