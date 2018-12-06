/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 08:57:49 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/22 15:12:00 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#	define PW(s) write(parse(s,stack_a,stack_b),CONCAT(s,"\n"),ft_strlen(s)+1)

int	algo3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size > 2 && stack_b->data[0] < stack_b->data[stack_b->size -
			1])
	{
		if (stack_b->data[1] < stack_b->data[stack_b->size - 1])
			return (PW("rrb"));
		return (PW("rb"));
	}
	if (stack_b->size > 1 && stack_b->data[0] < stack_b->data[1])
		return (PW("sb"));
	return (PW("pa"));
}

int	algo2(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->data[0] > stack_a->data[1])
	{
		if (stack_b->size > 1 && stack_b->data[0] < stack_b->data[1])
			return (PW("ss"));
		return (PW("sa"));
	}
	if (stack_b->size > 2 && stack_b->data[0] < stack_b->data[stack_b->size -
			1])
	{
		if (stack_b->data[1] < stack_b->data[stack_b->size - 1])
			return (PW("rrb"));
		return (PW("rb"));
	}
	if (stack_b->size > 1 && stack_b->data[0] < stack_b->data[1])
		return (PW("sb"));
	return (PW("pb"));
}

int	algo1(t_stack *stack_a, t_stack *stack_b)
{
	if (evaluate(stack_a, stack_b))
		return (0);
	if (!sorted(stack_a))
	{
		if (stack_a->data[0] > stack_a->data[stack_a->size - 1] && stack_b->size
				> 2 && stack_b->data[0] < stack_b->data[stack_b->size - 1])
		{
			if (stack_a->data[1] > stack_a->data[stack_a->size - 1])
			{
				if (stack_b->data[1] > stack_b->data[stack_b->size - 1])
					return (PW("rrr"));
				return (PW("rra"));
			}
			return (PW("ra"));
		}
		if (stack_a->data[0] > stack_a->data[stack_a->size - 1])
		{
			if (stack_a->data[1] > stack_a->data[stack_a->size - 1])
				return (PW("rra"));
			return (PW("ra"));
		}
		return (algo2(stack_a, stack_b));
	}
	return (algo3(stack_a, stack_b));
}
