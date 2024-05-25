/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:36:40 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/25 18:57:14 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	print_philo(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->rule->print);
	if (i == FORK)
		printf(MES_FORK, philo->id, philo->rule->time);
	else if (i == THINK)
		printf(MES_THINK, philo->id, philo->rule->time);
	else if (i == SLEEP)
		printf(MES_SLEEP, philo->id, philo->rule->time);
	else if (i == EAT)
	{
		printf(MES_FORK, philo->id, philo->rule->time);
		printf(MES_EAT, philo->id, philo->rule->time);
	}
	pthread_mutex_unlock(&philo->rule->print);
}
