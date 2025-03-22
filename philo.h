
#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

typedef enum e_state
{
	THINKING = 1,
	SLEEPING,
	EATING,
}	t_state;

/*
typedef enum e_set
{
	WAIT = 0,
	SEND_SIG,
}	t_set;
*/

typedef struct s_philo t_philo;

typedef struct s_mutex 
{
	bool dead;
	pthread_mutex_t death;
}	t_mutex;


typedef struct s_data
{
	int total_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nb_times_to_eat;
	pthread_mutex_t is_writing;
	t_philo *dinner;
	t_mutex *death;
	pthread_t monitor;
	
}	t_data;

typedef struct s_philo
{
	t_state	state;
	int pos_philo;
	t_mutex *dead;
	pthread_mutex_t *right_fork;
	pthread_mutex_t left_fork;
	pthread_mutex_t last_meal_lock;
	pthread_t	id;
	long int last_meal_time;
	t_data	*data;
}	t_philo;





void print_actions(int pos, t_state *state);
void *create_routine(void *args);
ssize_t ft_init_philo(t_data *data, t_philo *philo);
int ft_atoi(char *str);
int is_dead(t_philo *philo);
void give_philo_a_thread(t_data *data);
void join_the_philo(t_data *data);
long int get_the_time(void);

#endif