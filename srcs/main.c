/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:25 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/20 13:27:11 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
	free_all(philo, rule);
	return (0);
}
