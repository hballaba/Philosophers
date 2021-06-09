/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:16:27 by hballaba          #+#    #+#             */
/*   Updated: 2020/12/08 16:16:29 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int	ft_len(long int number)
{
	int	i;

	i = 0;
	if (number == 0)
		return (1);
	if (number < 0)
	{
		number = number * (-1);
		i = 1;
	}
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	long int	number;
	char		*str;
	size_t		i;

	number = n;
	i = ft_len(number);
	str = (char*)malloc(sizeof(char) * i + 1);
	if (str == NULL)
		return (NULL);
	str[i] = '\0';
	if (number == 0)
		str[0] = 48;
	if (number < 0)
	{
		str[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		str[--i] = number % 10 + 48;
		number /= 10;
	}
	return (str);
}

size_t		ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			ft_atoi(char *str)
{
	int			neg;
	long int	number;

	neg = 1;
	number = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\v' || *str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - 48);
		str++;
	}
	return (number * neg);
}

void		ft_putstr_fd(char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
