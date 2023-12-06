/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_functions.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:10:59 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 00:59:05 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **a)
{
	t_stack	*last;
	int		len;

	len = len_stack(*a);
	if (!a || !(*a) || len == 1)
		return ;
	last = ft_stacklast(*a);
	last->prev->next = NULL;
	last->next = *a;
	last->prev = NULL;
	*a = last;
	last->next->prev = last;
}

void	rra(t_stack **a, int checker)
{
	reverse_rotate(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int checker)
{
	reverse_rotate(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		write(1, "rrr\n", 4);
}
