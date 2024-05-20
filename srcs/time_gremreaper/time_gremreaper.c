/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_gremreaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 16:35:18 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/20 17:23:50 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	get_time(t_rule *r)
{
	int	t;

	r->time = 0;
	gettimeofday(&r->start, NULL);
	while (1)
	{
		gettimeofday(&r->now, NULL);
		t = r->now.tv_usec - r->start.tv_usec;
		if (t > 0)
		{
			t = t / 1000;
			r->time = (r->now.tv_sec - r->start.tv_sec) * 1000 + t;
		}
		else
		{
			t = (-1 * t) / 1000;
			r->time = (r->now.tv_sec - r->start.tv_sec) * 1000 - t;
		}
		usleep(400);
		if (r->dead_flag == 1)
			break ;
	}
}

void	grem_reaper(t_rule *rule)
{
	int	i;
	int	j;

	i = 0;
	while (rule->dead_flag == 0)
	{
		j = rule->philos[i].last_meal;
		if (rule->die < rule->time - j)
		{
			rule->dead_flag = 1;
			break ;
		}
		i ++;
		if (i == rule->number)
			i = 0;
		usleep(100);
	}
}
