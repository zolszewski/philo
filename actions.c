#include "philo.h"

void is_sleeping(t_philo *philo)
{
    if ((*philo).state == EATING)
    {
        pthread_mutex_lock(&(*(*philo).data).is_writing);
        pthread_mutex_lock(&(*philo).last_meal_lock);
        (*philo).last_meal_time = get_the_time();
        (*philo).state = SLEEPING;
        pthread_mutex_unlock(&(*philo).last_meal_lock);
        print_actions((*philo).pos_philo, &(*philo).state); 
        pthread_mutex_unlock(&(*(*philo).data).is_writing);
        usleep((*philo).data->time_to_sleep * 1000);
        (*philo).state = THINKING;
        pthread_mutex_lock(&(*(*philo).data).is_writing);
        print_actions((*philo).pos_philo, &(*philo).state);
        pthread_mutex_unlock(&(*(*philo).data).is_writing);
    }
    
}


void is_eating(t_philo *philo)
{
    pthread_mutex_lock(&(*philo).left_fork);
    pthread_mutex_lock((*philo).right_fork);
    pthread_mutex_lock(&(*(*philo).data).is_writing);
    printf("Philo %d has taken a fork", (*philo).pos_philo);
    printf("Philo %d has taken a fork", (*philo).pos_philo);
    (*philo).state = EATING;
    print_actions((*philo).pos_philo, &(*philo).state);
    pthread_mutex_unlock(&(*(*philo).data).is_writing);
    usleep((*philo).data->time_to_eat * 1000);
    if ((*(*philo).data).nb_times_to_eat)
        (*philo).data->nb_times_to_eat--; 
    pthread_mutex_unlock(&(*philo).left_fork);
    pthread_mutex_unlock((*philo).right_fork);
}

int is_dead(t_philo *philo)
{
	if ((*philo).dead == 1)
    {
        pthread_mutex_lock(&(*(*philo).dead).death);
        printf("Philosopher %d is dead\n", (*philo).pos_philo);
        (*(*philo).dead).dead = 1;
        pthread_mutex_unlock(&philo->dead->death);
        return (1);
    }
	return (0);
}



void *create_routine(void *args)
{
	t_philo *philo = (t_philo *)args;
	while (!is_dead(philo))
	{
		is_eating(philo);
        printf("eating philo nb%d\n", (*philo).pos_philo);
		is_sleeping(philo);
	}
    return (NULL);
}