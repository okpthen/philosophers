/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_gremreaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:35:18 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/25 20:07:30 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	get_time_sub(int sec, int msec)
{
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

void	*get_time(void *arg)
{
	int		msec;
	int		sec;
	t_rule	*r;

	r = arg;
	r->time = 0;
	gettimeofday(&r->start, NULL);
	while (1)
	{
		gettimeofday(&r->now, NULL);
		msec = r->now.tv_usec - r->start.tv_usec;
		sec = (r->now.tv_sec - r->start.tv_sec) * 1000;
		r->time = get_time_sub(sec, msec);//共有データ
		if (r->end == 1)
			break ;
	}
	return (NULL);
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
		j = rule->philos[i].last_meal;//共有データ
		if (rule->die < rule->time - j)
		{
			rule->end = 1;//共有データ
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
