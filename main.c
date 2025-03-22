#include "philo.h"
#include <stdio.h>


void print_actions(int pos, t_state *state)
{
    if (*(state + pos) == THINKING)
        printf("Philo %d is thinking", pos);
    else if (*(state + pos) == SLEEPING)
        printf("Philo %d is sleeping", pos);
    else if (*(state + pos) == EATING)
        printf("Philo %d is eating", pos);
    
}

void fill_data(int argc, char **argv, t_data *data)
{
    (*data).total_philo = ft_atoi(argv[1]);
    printf("totalphilo = %d\n", (*data).total_philo);
    if (ft_atoi(argv[1]) == 0)
        write(1, "number of philosophers incorrect", 32);
    (*data).time_to_die = ft_atoi(argv[2]);
    if (ft_atoi(argv[2]) == 0)
        write(1, "incorrect time", 14);
    (*data).time_to_eat = ft_atoi(argv[3]);
    if (ft_atoi(argv[3]) == 0)
        write(1, "incorrect time", 14);
    (*data).time_to_sleep = ft_atoi(argv[4]);
    if (ft_atoi(argv[3]) == 0)
        write(1, "incorrect time", 14);
    if (argc == 6)
    {
        (*data).nb_times_to_eat = ft_atoi(argv[5]);
        if (ft_atoi(argv[5]) == 0)
            write(1, "no meal needed", 14);
    }
    printf("data filled with argv3 = %d\n", (*data).time_to_eat);
}

int main(int argc, char **argv)
{
    t_data data;
    t_philo philo;
    if (argc < 5)
        return (write(STDOUT_FILENO, "invalid number of arguments", 27), 1);
    else
    {
        fill_data(argc, argv, &data);
        ft_init_philo(&data, &philo);
        give_philo_a_thread(&data);
        join_the_philo(&data);
    }
    return (0);
}