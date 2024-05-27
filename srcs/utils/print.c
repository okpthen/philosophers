/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 18:36:40 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/27 15:34:01 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	print_philo(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->rule->print);
	if (i == FORK)
		printf(MES_FORK, get_time(0), philo->id);
	else if (i == THINK)
		printf(MES_THINK, get_time(0), philo->id);
	else if (i == SLEEP)
		printf(MES_SLEEP, get_time(0), philo->id);
	else if (i == EAT)
	{
		printf(MES_FORK, get_time(0), philo->id);
		printf(MES_EAT, get_time(0), philo->id);
	}
	pthread_mutex_unlock(&philo->rule->print);
}
