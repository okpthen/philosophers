/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kazuhiro <kazuhiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:15:17 by kazokada          #+#    #+#             */
/*   Updated: 2024/05/20 03:16:22 by kazuhiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <pthread.h>

typedef struct s_rule
{
	int				number;
	int				die;
	int				eat;
	int				sleep;
	int				finish;
	int				time;
	pthread_mutex_t	print;
}	t_rule;

typedef struct s_philo
{
	int				id;
	int				last_meal;
	int				meal_time;
	int				status;
	pthread_t		t_id;
	t_rule			*rule;
	pthread_mutex_t	right;
	pthread_mutex_t	left;
}	t_philo;

#endif