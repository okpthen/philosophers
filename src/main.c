/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:25 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/20 11:57:49 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_rule	*rule;
	t_philo	*philo;

	if (argc < 5  || 6 < argc || check_input(rule, argv))
		printf("input correct arg\n");
	philo = init_philo(rule);
	free(philo);
	return (0);
}
