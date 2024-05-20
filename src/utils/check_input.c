/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 10:50:33 by kazuhiro          #+#    #+#             */
/*   Updated: 2024/05/20 11:53:25 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	check_input(t_rule *rule, char **argv)
{
	int	i;
	int	c;

	rule->number = ft_atoi(argv[1]);
	rule->die = ft_atoi(argv[2]);
	rule->eat = ft_atoi(argv[3]);
	rule->sleep = ft_atoi(argv[4]);
	if (argv[5])
		rule->finish = ft_atoi(argv[5]);
	else
		rule->finish = 0;
	if (rule->number < 0 || rule->die < 0 || rule->eat < 0
		|| rule ->sleep < 0 || rule ->time < 0)
		return (1);
	rule->time = -1;
	rule->dead_flag = 0;
	return (0);
}
