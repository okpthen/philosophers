/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazokada <kazokada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:15:17 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/27 15:28:41 by kazokada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_rule
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				finish;
	int				end;
	pthread_mutex_t	print;
	pthread_mutex_t	end_m;
	pthread_mutex_t	*forks;
	pthread_t		grem_reaper;
	pthread_t		clock;
	pthread_t		finish_meal;
	t_philo			*philos;
}	t_rule;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				meal_time;
	int				status;
	pthread_t		t_id;
	t_rule			*rule;
	pthread_mutex_t	meal;
	pthread_mutex_t	*right;
	pthread_mutex_t	*left;
}	t_philo;

#endif