/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rutine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 16:09:22 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/27 01:20:41 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	report_meal(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal);
	philo->meal_time ++;
	pthread_mutex_lock(&philo->rule->time_m);
	philo->last_meal = philo->rule->time;
	pthread_mutex_unlock(&philo->rule->time_m);
	pthread_mutex_unlock(&philo->meal);
}

void	philo_eat_even(t_philo *philo)
{
	pthread_mutex_lock(philo->right);
	if (philo->rule->end == 1)
	{
		pthread_mutex_unlock(philo->right);
		return ;
	}
	print_philo(philo, FORK);
	pthread_mutex_lock(philo->left);
	if (philo->rule->end == 1)
	{
		pthread_mutex_unlock(philo->left);
		pthread_mutex_unlock(philo->right);
		return ;
	}
	print_philo(philo, EAT);
	report_meal(philo);
	while (philo->rule->end == 0 && ((philo->rule->time - philo->last_meal)
			< philo->rule->eat + 1))
	{
		usleep(500);
	}
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	philo_eat_odd(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	if (philo->rule->end == 1)
	{
		pthread_mutex_unlock(philo->left);
		return ;
	}
	print_philo(philo, FORK);
	pthread_mutex_lock(philo->right);
	if (philo->rule->end == 1)
	{
		pthread_mutex_unlock(philo->right);
		pthread_mutex_unlock(philo->left);
		return ;
	}
	print_philo(philo, EAT);
	report_meal(philo);
	while (philo->rule->end == 0 && ((philo->rule->time - philo->last_meal)
			< philo->rule->eat + 1))
	{
		usleep(100);
	}
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	*philo_rutine(void *arg)
{
	t_philo	*philo;
	int		i;

	i = 0;
	philo = arg;
	while (philo->rule->end == 0)
	{
		if (philo->id % 2 == 0 && i == 0)
		{
			usleep(1000);
			philo_eat_odd(philo);
		}
		else if (philo->id % 2 == 1 && i == 0)
			philo_eat_odd(philo);
		else
			philo_eat_odd(philo);
		i = 1;
		philo_sleeping(philo);
		philo_thinking(philo);
	}
	return (NULL);
}
