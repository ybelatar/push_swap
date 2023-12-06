/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:10:56 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 00:58:58 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **a, t_stack **b)
{
	t_stack	*pushed;

	if (!(*a))
		return ;
	pushed = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	pushed->prev = NULL;
	if (!*b)
	{
		*b = pushed;
		(*b)->next = NULL;
	}
	else
	{
		pushed->next = *b;
		pushed->next->prev = pushed;
		*b = pushed;
	}
}

void	pa(t_stack **a, t_stack **b, int checker)
{
	push(b, a);
	if (!checker)
		write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a, int checker)
{
	push(a, b);
	if (!checker)
		write(1, "pb\n", 3);
}
