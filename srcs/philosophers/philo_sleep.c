/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:29:06 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/29 12:37:15 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	check_end(t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&philo->rule->end_m);
	if (philo->rule->end == 1)
		i = 1;
	pthread_mutex_unlock(&philo->rule->end_m);
	return (i);
}

void	philo_sleeping(t_philo *philo)
{
	long	start;

	print_philo(philo, SLEEP);
	start = get_time();
	while ((get_time() - start) < philo->rule->sleep + 1)
	{
		if (check_end(philo))
			break ;
	}
	print_philo(philo, THINK);
}
