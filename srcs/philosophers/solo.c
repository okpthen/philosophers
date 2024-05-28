/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:26:34 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/28 15:06:23 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	*philo_solo(void *arg)
{
	t_philo	*philo;

	philo = arg;
	print_philo(philo, FORK);
	while (philo->rule->end == 0 && ((get_time(0) - philo->last_meal)
			< philo->rule->eat + 1))
		usleep(500);
	return (NULL);
}
