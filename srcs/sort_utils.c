/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 01:58:11 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 00:59:56 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_smallest(t_stack *a)
{
	t_stack	*smallest;

	if (!a)
		return (NULL);
	smallest = a;
	while (a)
	{
		if (a->value < smallest->value)
			smallest = a;
		a = a->next;
	}
	return (smallest);
}

t_stack	*find_cheapest(t_stack *b)
{
	if (!b)
		return (NULL);
	while (b)
	{
		if (b->cheapest)
			return (b);
		b = b->next;
	}
	return (NULL);
}

void	ft_lstdelone(t_stack *lst)
{
	if (!lst)
		return ;
	if (lst)
		free(lst);
}

void	set_rest(t_stack *b, t_stack *cheapest)
{
	while (b)
	{
		if (b != cheapest)
			b->cheapest = 0;
		b = b->next;
	}
}
