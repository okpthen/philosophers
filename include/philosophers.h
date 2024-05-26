/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:05:15 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/27 01:08:32 by kazuhiro         ###   ########.fr       */
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
# define FORK 4
# define PHILO_MAX 300

# define MES_FORK "%d %d has taken a fork\n"
# define MES_THINK "%d %d is thinking\n"
# define MES_SLEEP "%d %d is sleeping\n"
# define MES_EAT "%d %d is eating\n"

int		ft_atoi(char *str);
t_rule	*check_input(char **argv);
t_philo	*init_philo(t_rule *rule);
void	free_all(t_philo *philo, t_rule *rule);
void	*philo_rutine(void *arg);
void	*grem_reaper(void *arg);
void	*get_time(void *arg);
void	print_philo(t_philo *philo, int i);
void	philo_sleeping(t_philo *philo);
void	philo_thinking(t_philo *philo);
void	*count_meal_time(void *arg);
void	*philo_solo(void *arg);

#endif