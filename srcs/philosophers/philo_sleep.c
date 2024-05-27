/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:29:06 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/27 15:32:33 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	philo_sleeping(t_philo *philo)
{
	int	start;

	start = get_time(0);
	if (philo->rule->end == 0)
		print_philo(philo, SLEEP);
	while ((get_time(0) - start) < philo->rule->sleep + 1)
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
