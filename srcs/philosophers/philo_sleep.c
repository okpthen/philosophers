/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:29:06 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/26 15:23:03 by kazokada         ###   ########.fr       */
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
	while ((philo->rule->time - start) < philo->rule->sleep + 1)
	{
		if (philo->rule->end == 1)
			break ;
	}
}

void	philo_thinking(t_philo *philo)
{
	if (philo->rule->end == 1)
		return ;
	print_philo(philo, THINK);
}
