/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:15:43 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 02:18:59 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stacklast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

int	len_stack(t_stack *a)
{
	int	i;

	if (!a)
		return (0);
	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	sorted_stack(t_stack *a)
{
	if (!a)
		return (1);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

t_stack	*find_biggest(t_stack *a)
{
	t_stack	*biggest;

	if (!a)
		return (NULL);
	biggest = a;
	while (a)
	{
		if (a->value > biggest->value)
			biggest = a;
		a = a->next;
	}
	return (biggest);
}

void	add_stack(t_stack **a, int n)
{
	t_stack	*last;
	t_stack	*new;

	if (!a)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->next = NULL;
	new->value = n;
	new->cheapest = 0;
	if (!(*a))
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_stacklast(*a);
		new->prev = last;
		last->next = new;
	}
}
