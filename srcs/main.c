/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:49:54 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 00:58:50 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		free_bool;

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
	if (!sorted_stack(a))
	{
		if (len_stack(a) == 2)
			ra(&a, 0);
		else if (len_stack(a) == 3)
			tiny_sort(&a);
		else
			sort_stack(&a, &b);
	}
	free_stack(&a);
}
