/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:29:06 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/25 20:35:55 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	philo_sleeping(t_philo *philo)
{
	int	start;

	pthread_mutex_lock(&philo->rule->time_m);
	start = philo->rule->time;
	pthread_mutex_unlock(&philo->rule->time_m);
	if (philo->rule->end == 0)
		print_philo(philo, SLEEP);
	while (philo->rule->time - start < philo->rule->sleep)
	{
		if (philo->rule->end == 1)
			break ;
	}
}
