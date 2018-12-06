/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 11:03:07 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/27 14:30:19 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *stack)
{
	int a;
	int b;

	a = -1;
	b = 0;
	while (++a < stack->size)
		if (stack->data[a] > b)
			b = stack->data[a];
	return (b);
}

int	sorted(t_stack *stack)
{
	int a;

	a = -1;
	while (++a < stack->size - 1)
		if (stack->data[a] > stack->data[a + 1])
			return (0);
	a = -1;
	while (stack->data[0] == 1 && ++a < stack->size - 1)
		if (stack->data[a] + 1 != stack->data[a + 1])
			return (1);
	return (1);
}
