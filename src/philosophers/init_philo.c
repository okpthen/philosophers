/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 11:09:19 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/20 11:35:40 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

void	philo_forks(t_philo philo, pthread_mutex_t *fork, int i, int max)
{
	if (i = 0)
		philo.right = fork[max - 1];
	else
		philo.right = fork[i - 1];
	philo.left = fork[i];
}

void	init_fork(pthread_mutex_t *fork, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&fork[i], NULL);
		i ++;
	}
}

t_philo	*init_philo(t_rule *rule)
{
	t_philo			*philo;
	pthread_mutex_t	*fork;
	int				i;

	i = 0;
	philo = malloc (sizeof(t_philo) * rule->number);
	fork = malloc (sizeof(pthread_mutex_t) * rule->number);
	init_fork(fork, rule->number);
	while (i < rule->number)
	{
		philo[i].id = i + 1;
		philo[i].last_meal = 0;
		philo[i].status = 0;
		philo[i].rule = rule;
		philo_forks(philo[i], fork, i, rule->number);
		i ++;
	}
}
