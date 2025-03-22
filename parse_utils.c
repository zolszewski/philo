#include "philo.h"

int ft_atoi(char *str)
{
    int result;
    int i;

    i = 0 ;
    result = 0;
    if (str[i] == '0')
        return (0);
    if (str[i] == '-')
            return (0);
    while (str[i] >= '0' && str[i] <= '9')
    {
        result *= 10;
        result += (str[i] - '0') ;
        i++;
    }
    return (result);

}