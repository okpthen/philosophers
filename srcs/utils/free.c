/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:58:22 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/25 20:07:57 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	free_all(t_philo *philo, t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->number)
	{
		pthread_mutex_destroy(&rule->forks[i]);
		pthread_mutex_destroy(&philo[i].meal);
		i ++;
	}
	pthread_mutex_destroy(&rule->time_m);
	pthread_mutex_destroy(&rule->print);
	pthread_mutex_destroy(&rule->end);
	free(rule->forks);
	free(philo);
	free(rule);
}
