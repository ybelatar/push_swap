/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 18:55:52 by ybelatar          #+#    #+#             */
/*   Updated: 2023/12/06 18:44:31 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_syntax(char *str)
{
	int	i;

	i = 0;
	if (!(str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9')))
		return (1);
	if ((str[i] == '+' || str[i] == '-') && !(str[i + 1] >= '0' && str[i
				+ 1] <= '9'))
		return (1);
	i++;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	error_repeated(t_stack *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_matrix(char **argv)
{
	int	i;

	if (!argv || !(*argv))
		return ;
	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv - 1);
	return ;
}

void	free_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = tmp;
	}
}

void	free_all(t_stack **a, char **argv, int free_bool)
{
	free_stack(a);
	if (free_bool)
		free_matrix(argv);
	write(2, "Error\n", 6);
	exit(1);
}
