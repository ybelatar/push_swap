/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:58:14 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 00:56:16 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_all(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b, 0);
	set_current_pos(*a);
	set_current_pos(*b);
}

void	reverse_rotate_all(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b, 0);
	set_current_pos(*a);
	set_current_pos(*b);
}

void	set_rotation(t_stack **a, t_stack *cell, int id)
{
	while (*a != cell)
	{
		if (id)
		{
			if (cell->upper_half)
				ra(a, 0);
			else
				rra(a, 0);
		}
		else
		{
			if (cell->upper_half)
				rb(a, 0);
			else
				rrb(a, 0);
		}
	}
}

void	put_right_place(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	cheapest = find_cheapest(*b);
	if (cheapest->upper_half && cheapest->target->upper_half)
		rotate_all(a, b, cheapest);
	else if (!(cheapest->upper_half) && !(cheapest->target->upper_half))
		reverse_rotate_all(a, b, cheapest);
	set_rotation(a, cheapest->target, 1);
	set_rotation(b, cheapest, 0);
	pa(a, b, 0);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	t_stack	*smallest;
	int		len;

	len = len_stack(*a);
	while (len-- > 3)
		pb(b, a, 0);
	tiny_sort(a);
	while (*b)
	{
		set_params(*a, *b);
		put_right_place(a, b);
	}
	smallest = find_smallest(*a);
	if (smallest->upper_half)
	{
		while (*a != smallest)
			ra(a, 0);
	}
	else
	{
		while (*a != smallest)
			rra(a, 0);
	}
}
