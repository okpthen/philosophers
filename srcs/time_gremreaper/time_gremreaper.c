/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_gremreaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:35:18 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/28 15:06:19 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	get_time_sub(struct timeval *start)
{
	struct timeval	now;
	int				msec;
	int				sec;

	gettimeofday(&now, NULL);
	sec = (now.tv_sec - start->tv_sec) * 1000;
	msec = now.tv_usec - start->tv_usec;
	if (msec > 0)
	{
		msec = msec / 1000;
		return (sec + msec);
	}
	else
	{
		msec = (-1 * msec) / 1000;
		return (sec - msec);
	}
	return (0);
}

int	get_time(int i)
{
	static struct timeval	*start;

	if (i == 1)
	{
		start = malloc (sizeof (struct timeval));
		gettimeofday(start, NULL);
		return (0);
	}
	if (start == NULL)
		return (0);
	if (i == 0)
		return (get_time_sub(start));
	if (i == 2)
		free(start);
	return (0);
}

void	*grem_reaper(void *arg)
{
	int		i;
	int		j;
	t_rule	*rule;

	i = 0;
	rule = arg;
	while (rule->end == 0)
	{
		pthread_mutex_lock(&rule->philos[i].meal);
		j = rule->philos[i].last_meal;
		pthread_mutex_unlock(&rule->philos[i].meal);
		if (rule->die < (get_time(0) - j + 1))
		{
			rule->end = 1;
			printf("%d %d died\n", get_time(0), i +1);
			break ;
		}
		i ++;
		if (i == rule->number)
			i = 0;
		usleep(100);
	}
	return (NULL);
}

void	*count_meal_time(void *arg)
{
	int		i;
	t_rule	*rule;
	int		j;

	rule = arg;
	i = 0;
	if (rule->finish == 0)
		return (NULL);
	while (rule->end == 0)
	{
		usleep(100);
		pthread_mutex_lock(&rule->philos[i].meal);
		j = rule->philos[i].meal_time;
		pthread_mutex_unlock(&rule->philos[i].meal);
		if (rule->finish > j)
		{
			i = 0;
			continue ;
		}
		i ++;
		if (i == rule->number)
			rule->end = 1;
	}
	return (NULL);
}
