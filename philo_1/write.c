/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hballaba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 16:16:44 by hballaba          #+#    #+#             */
/*   Updated: 2020/12/08 16:16:48 by hballaba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t count;
	size_t i;

	count = 0;
	if (!dst)
		return (0);
	if (!size)
		return (ft_strlen((char*)src));
	while (src[count] != '\0')
		count++;
	i = 0;
	while (src[i] != '\0' && size > 1)
	{
		dst[i] = src[i];
		i++;
		size--;
	}
	dst[i] = '\0';
	return (count);
}

static size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t lendst;
	size_t lensrc;

	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char*)src);
	i = lendst + lensrc;
	dst[lendst] = ' ';
	lendst++;
	while (*src && size > lendst + 1)
	{
		dst[lendst] = *src;
		src++;
		lendst++;
	}
	dst[lendst] = '\0';
	return (i);
}

static char		*ft_strjoin_write(char *s1, char *s2, char const *s3)
{
	char	*str;
	size_t	lens1;
	size_t	lens2;
	size_t	lens3;

	lens1 = ft_strlen((char*)s1);
	lens2 = ft_strlen((char*)s2);
	lens3 = ft_strlen((char*)s3);
	if (!(str = (char*)malloc(lens1 + lens2 + lens3 + 4)))
		ft_error_malloc();
	ft_strlcpy(str, s1, lens1 + 1);
	ft_strlcat(str, s2, lens2 + lens1 + 2);
	ft_strlcat(str, s3, lens3 + lens2 + lens1 + 3);
	str[lens3 + lens2 + lens1 + 2] = '\n';
	str[lens3 + lens2 + lens1 + 3] = '\0';
	free(s1);
	s1 = NULL;
	free(s2);
	s2 = NULL;
	return (str);
}

void			ft_write_messege(t_kant *kant, int i, char *str)
{
	int		diff;
	char	*print;

	diff = ft_time() - kant->start_time;
	print = ft_strjoin_write(ft_itoa(diff), ft_itoa(++i), str);
	pthread_mutex_lock(&kant->table->mutex_write);
	if (kant->table->flag_write_dead == 1)
	{
		write(1, print, ft_strlen(print));
	}
	pthread_mutex_unlock(&kant->table->mutex_write);
	free(print);
	print = NULL;
}
