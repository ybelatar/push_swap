/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 01:13:12 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 02:25:38 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "push_swap.h"

void	error_exit(char *str, t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
	free(str);
	write(2, "Error\n", 6);
	exit(1);
}

void	command(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "pa\n"))
		pa(a, b, 1);
	else if (!ft_strcmp(str, "pb\n"))
		pb(b, a, 1);
	else if (!ft_strcmp(str, "sa\n"))
		sa(a, 1);
	else if (!ft_strcmp(str, "sb\n"))
		sb(b, 1);
	else if (!ft_strcmp(str, "ss\n"))
		ss(a, b, 1);
	else if (!ft_strcmp(str, "ra\n"))
		ra(a, 1);
	else if (!ft_strcmp(str, "rb\n"))
		rb(b, 1);
	else if (!ft_strcmp(str, "rr\n"))
		rr(a, b, 1);
	else if (!ft_strcmp(str, "rra\n"))
		rra(a, 1);
	else if (!ft_strcmp(str, "rrb\n"))
		rrb(b, 1);
	else if (!ft_strcmp(str, "rrr\n"))
		rrr(a, b, 1);
	else
		error_exit(str, a, b);
}

void	listen_instructions(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		command(str, a, b);
		free(str);
		str = get_next_line(0);
	}
}

int	check(t_stack *a, t_stack *b)
{
	if (sorted_stack(a) && !b)
	{
		write(1, "OK\n", 3);
		return (1);
	}
	else
	{
		write(1, "KO\n", 3);
		return (0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		free_bool;
	int		boo;

	free_bool = 0;
	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		free_bool = 1;
	}
	fill_stack(&a, argv + 1, free_bool);
	listen_instructions(&a, &b);
	boo = check(a, b);
	free_stack(&a);
	if (!boo)
		free_stack(&b);
}
