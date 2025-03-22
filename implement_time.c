#include "philo.h"

long int get_the_time(void)
{
    long int time;
    struct timeval current_time;

    time = 0;
    if (gettimeofday(&current_time, NULL) == -1);
        return (write(2, "gettimeof day failed", 20));
    time = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
    return (time);
}



