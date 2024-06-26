/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjeuneje <sjeuneje@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:20:37 by sjeuneje          #+#    #+#             */
/*   Updated: 2022/06/09 16:07:01 by sjeuneje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	print_error()
{
	printf("Error: wrong argument(s).\n");
	return (1);
}

static int	in_limits(char **arr_numbers)
{
	int	i;

	i = 1;
	while (arr_numbers[i])
	{
		if (ft_atoi(arr_numbers[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}


static int	is_num(char *str)
{
	int	i;

	if (str[0] == '+' || str[0] == '-')
		i = 1;
	else
		i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	check_args(char **ar)
{
	int	i;

	i = 1;
	while (ar[i])
	{
		if (!is_num(ar[i]))
			return (0);
		i++;
	}
	return (1);
}

int	error_handler(int ac, char **ar)
{
	if (ac != 5 && ac != 6)
		return (print_error());
	if (!check_args(ar))
		return (print_error());
	if (!in_limits(ar))
		return (print_error());
	return (0);
}
