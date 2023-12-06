/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelatar <ybelatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 16:34:36 by ybelatar          #+#    #+#             */
/*   Updated: 2023/11/27 02:18:47 by ybelatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				pos;
	int				price;
	int				upper_half;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

/*Push functions*/
void				pa(t_stack **a, t_stack **b, int checker);
void				pb(t_stack **b, t_stack **a, int checker);

/*Rotation functions*/
void				rra(t_stack **a, int checker);
void				rrb(t_stack **b, int checker);
void				rrr(t_stack **a, t_stack **b, int checker);

/*Reverse rotation functions*/
void				ra(t_stack **a, int checker);
void				rb(t_stack **b, int checker);
void				rr(t_stack **a, t_stack **b, int checker);

/*Swap functions*/
void				sa(t_stack **a, int checker);
void				sb(t_stack **b, int checker);
void				ss(t_stack **a, t_stack **b, int checker);

/*Initializing the first stack with the input*/
void				fill_stack(t_stack **a, char **argv, int free_bool);

/*Utils functions (not important but essential)*/
t_stack				*ft_stacklast(t_stack *lst);
int					len_stack(t_stack *a);
int					sorted_stack(t_stack *a);
t_stack				*find_biggest(t_stack *a);
void				add_stack(t_stack **a, int n);
t_stack				*find_smallest(t_stack *a);
void				set_current_pos(t_stack *a);
t_stack				*find_cheapest(t_stack *b);
void				set_rest(t_stack *b, t_stack *cheapest);
int					ft_strcmp(char *s1, char *s2);

/*The split function used is a little tweaked compared to the original one*/
char				**ft_split(char const *s, char c);

/*Sorting functions*/
void				set_params(t_stack *a, t_stack *b);
void				sort_stack(t_stack **a, t_stack **b);
void				tiny_sort(t_stack **a);

/*Free and error handling functions*/
void				free_stack(t_stack **a);
int					error_syntax(char *str);
int					error_repeated(t_stack *a, int n);
void				free_all(t_stack **a, char **argv, int free_bool);
void				free_matrix(char **argv);
void				ft_lstdelone(t_stack *lst);

#endif