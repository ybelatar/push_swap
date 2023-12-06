/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:00:21 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 02:21:50 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	nbr;
	int		signe;
	int		i;

	i = 0;
	nbr = 0;
	signe = 1;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 15)))
		i++;
	if (str[i] == '-')
	{
		signe *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	return (nbr * signe);
}

void	fill_stack(t_stack **a, char **argv, int free_bool)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			free_all(a, argv, free_bool);
		n = ft_atol(argv[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_all(a, argv, free_bool);
		if (error_repeated(*a, (int)n))
			free_all(a, argv, free_bool);
		add_stack(a, (int)n);
		i++;
	}
	if (free_bool)
		free_matrix(argv);
}
