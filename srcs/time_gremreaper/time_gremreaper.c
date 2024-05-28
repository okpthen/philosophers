/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_gremreaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:35:18 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/28 23:20:02 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	*grem_reaper(void *arg)
{
	int		i;
	long	j;
	t_rule	*rule;

	i = 0;
	rule = arg;
	usleep(10000);
	while (rule->end == 0)
	{
		pthread_mutex_lock(&rule->philos[i].meal);
		j = rule->philos[i].last_meal;
		pthread_mutex_unlock(&rule->philos[i].meal);
		if (rule->die < (get_time() - j + 1))
		{
			rule->end = 1;
			printf("%ld %d died\n", get_time() - j, i +1);
			break ;
		}
		i ++;
		if (i == rule->number)
			i = 0;
		usleep(100);
	}
	(void)arg;
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
