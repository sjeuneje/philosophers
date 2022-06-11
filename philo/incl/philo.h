/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:20:37 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/06/09 18:45:25 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct	s_philo
{
	int					num;
	int					nb_eats;
	int					is_alive;
	unsigned long		last_eat;
	pthread_t			t;
	pthread_mutex_t		*fork_l;
	pthread_mutex_t		*fork_r;
}				t_philo;

typedef struct	s_data
{
	int	nb_philo;
	int	nb_philo_must_eat;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	full;
	int stop;
	unsigned long	start_time;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	talk;
	pthread_mutex_t	eat;
}				t_data;

/* errors */
int				error_handler(int ac, char **ar);

/* init */
int				init_params(t_data *data, int ac, char **ar);
int				init_philos(t_data *data);
int				init_forks(t_data *data);

/* utils */
int				ft_atoi(char *s);
unsigned long	ft_get_time();

/* threads */
int	launch_threads(t_data *data);

#endif