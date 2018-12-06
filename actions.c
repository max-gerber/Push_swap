/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 09:56:46 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/27 14:30:19 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int		i;

	if (stack->size < 2)
		return ;
	i = stack->data[0];
	stack->data[0] = stack->data[1];
	stack->data[1] = i;
}

int		pop(t_stack *stack)
{
	int a;
	int i;

	a = -1;
	i = stack->data[0];
	while (++a < stack->size - 1)
		stack->data[a] = stack->data[a + 1];
	stack->size--;
	return (i);
}

void	push(t_stack *stack, int a)
{
	int s;

	s = stack->size + 1;
	while (--s)
		stack->data[s] = stack->data[s - 1];
	stack->data[s] = a;
	stack->size++;
}

void	rotate(t_stack *stack)
{
	stack->data[stack->size++] = pop(stack);
}

void	rrotate(t_stack *stack)
{
	push(stack, stack->data[--stack->size]);
}
