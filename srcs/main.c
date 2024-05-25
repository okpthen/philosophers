/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:25 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/25 20:08:01 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	start_meal(t_philo *philo, t_rule *rule)
{
	int	i;

	i = 0;
	while (i < rule->number)
	{
		pthread_create(&philo[i].t_id, NULL, philo_rutine, &philo[i]);
		i ++;
	}
	pthread_create(&rule->grem_reaper, NULL, grem_reaper, rule);
	pthread_create(&rule->clock, NULL, get_time, rule);
	i = 0;
	while (i < rule->number)
	{
		pthread_join(philo[i].t_id, NULL);
		i ++;
	}
	pthread_join(rule->grem_reaper, NULL);
	pthread_join(rule->clock, NULL);
	printf("%d\n", rule->eat);
}

int	main(int argc, char **argv)
{
	t_rule	*rule;
	t_philo	*philo;

	if (argc < 5 || 6 < argc)
	{
		printf("input correct arg\n");
		return (0);
	}
	rule = check_input(argv);
	if (rule == NULL)
	{
		printf("input correct arg\n");
		return (0);
	}
	philo = init_philo(rule);
	// start_meal(philo, rule);
	free_all(philo, rule);
	return (0);
}
