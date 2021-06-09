/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tread2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 19:36:56 by hballaba          #+#    #+#             */
/*   Updated: 2020/12/09 19:37:22 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void		*loop(void *taaa)
{
	t_dobray	*table;
	int			i;

	table = taaa;
	i = -1;
	sem_wait(table->sem_dead);
	while (++i < table->num_phil)
	{
		kill(table->pid[i], SIGKILL);
	}
	return (taaa);
}
