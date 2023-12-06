/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:31:47 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 00:57:01 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	tiny_sort(t_stack **a)
{
	t_stack	*biggest;

	biggest = find_biggest(*a);
	if (*a == biggest)
		ra(a, 0);
	else if ((*a)->next == biggest)
		rra(a, 0);
	if ((*a)->value > (*a)->next->value)
		sa(a, 0);
}
