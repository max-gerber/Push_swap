/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:49:55 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/28 12:29:07 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define CONCAT(STR1, STR2) STR1 STR2

# include <unistd.h>
# include "./libft/includes/libft.h"

typedef struct		s_stack
{
	int				*data;
	int				size;
}					t_stack;

int					*args(int *ac, char **av);
int					*norm(int *stack, int size);
int					sorted(t_stack *stack);
int					max(t_stack *stack);
int					evaluate(t_stack *stack_a, t_stack *stack_b);
int					parse(char *line, t_stack *stack_a, t_stack *stack_b);
int					top_positions(t_stack stack, char c);
int					bubble(t_stack *stack_a, t_stack *stack_b);
int					sort_3(t_stack *stack_a, t_stack *stack_b);
int					algo1(t_stack *stack_a, t_stack *stack_b);
int					csort(t_stack *stack_a, t_stack *stack_b, int size, int n);
int					pop(t_stack *stack);
void				push(t_stack *stack, int a);
void				rotate(t_stack *stack);
void				rrotate(t_stack *stack);
void				swap(t_stack *stack);
void				valid_stack(t_stack stack);

#endif
