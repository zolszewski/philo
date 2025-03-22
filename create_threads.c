#include "philo.h"
#include <stdlib.h>

ssize_t ft_init_philo(t_data *data, t_philo *philo)
{
	int i = 0;
    pthread_t id;

    pthread_mutex_init(&(*data).death, NULL);
	(*data).dinner = (t_philo *)malloc(sizeof(t_philo) * (*data).total_philo);
    printf("id_thread created\n");  
	if (!(*data).dinner)
        return (0);
	while (i < (*data).total_philo)
	{
		(*data).dinner[i].pos_philo = i + 1;
		pthread_mutex_init(&(*data).dinner[i].left_fork, NULL);
		pthread_mutex_init(&(*data).is_writing, NULL);
		(*data).dinner[i].right_fork = NULL;
		(*data).dinner[i].data = data;
		(*data).dinner[i].state = THINKING;
		if (i == (*data).total_philo - 1)
			(*data).dinner[i].right_fork = &(*data).dinner[0].left_fork;
		else
			(*data).dinner[i].right_fork = &(*data).dinner[i + 1].left_fork;
        i++;
    }
	return (1);
}

void give_philo_a_thread(t_data *data)
{
	int i;

	i = 0;
	while (i < (*data).total_philo)
	{
		if(pthread_create(&(*data).dinner[i].id, NULL, create_routine, (void *)&(*data).dinner[i]))
            return (write(2, "thread creation failed", 22), (void)0);
		i++;
	}
	if (pthread_create(&(*data).monitor, NULL, check_death, (void *)&data))
		return (write(2, "thread creation failed", 22), (void)0);
}

void join_the_philo(t_data *data)
{
	int i;

	i = 0;
	while (i < (*data).total_philo)
	{
		if(pthread_join((*data).dinner[i].id, NULL))
            return (write(2, "thread join failed", 22), (void)0);
		i++;
	}
	if (pthread_join((*data).monitor, NULL))
		return (write(2, "thread join failed", 22), (void)0);
}


bool is_alive(t_philo *philo)
{

	{
		if (get_the_time() - (*philo).last_meal_time > (*(*philo).data).time_to_die)
		{
			pthread_mutex_lock(&philo->dead->death);
				(*(*philo).dead).dead = 1;
				


		}

	}
}

void check_death(void *data)
{
	t_data *data;
	int i;

	i = 0;
	data = (t_data *)data;
	while (is_alive(&(*data)))
	{
		
	}

}

int all_alive(t_data *data)
{
	int i;

	i = 0;
	while (i < (*data).total_philo)
	{	
		if (is_dead(&(*data).dinner[i]))
			return (0);
		i++;
	}
	return (1);
}
