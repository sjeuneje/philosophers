#include "errors_handler.h"

static int	print_error(int code)
{
	if (code == 0)
		printf("Error: incorrect number of arguments.\n");
	else if (code == 1)
		printf("Error: only numbers are accepted as arguments.\n");
	return (1);
}

static int	ft_is_num(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((*str >= 65 && *str <= 90) || (*str >= 97 && *str <= 122))
			return (0);
		i++;
	}
	return (1);
}

static int	check_args(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
	{
		if (!ft_is_num(*ar))
			return (0);
		i++;
	}
	return (1);
}

int	error_handler(int ac, char **ar)
{
	if (ac != 5 && ac != 6)
		return (print_error(0));
	if (!check_args(ar))
		return (print_error(1));
	return (0);
}
