/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:08:04 by abbahoua          #+#    #+#             */
/*   Updated: 2022/05/09 13:50:33 by abbahoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	ft_atoi(char *str)
{
	long long		nb;
	long long		sign;

	nb = 0;
	sign = 1;
	sign_issue(str);
	check_str(str);
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
			nb = (nb * 10) + (*str - '0');
			str++;
	}
	if ((nb * sign) > 2147483647 || (nb * sign) < -2147483648)
		ft_error();
	return (nb * sign);
}

int	dbquoates(char **av, int ac)
{
	int	i;

	i = 0;
	while (av[ac][i])
	{
		if (av[ac][i] == ' ')
			return (1);
		i++;
	}
	if (!i)
		ft_error();
	return (0);
}
