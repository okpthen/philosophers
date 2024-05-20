/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:05:15 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/20 13:00:36 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include "struct.h"

# define THINK 1
# define EAT 2
# define SLEEP 3

int		ft_atoi(char *str);
t_rule	*check_input(char **argv);
t_philo	*init_philo(t_rule *rule);
void	free_all(t_philo *philo, t_rule *rule);

#endif