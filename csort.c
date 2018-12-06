/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 11:59:12 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/27 12:16:08 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#	define PW(s) write(parse(s,stack_a,stack_b),CONCAT(s,"\n"),ft_strlen(s)+1)

int		move(t_stack *stack, int x)
{
	int a;
	int b;

	a = -1;
	b = 0;
	while (++a < stack->size && stack->data[a] != x)
		b++;
	if (b < stack->size / 2)
		return (b);
	return (stack->size - b);
}

int		depth(t_stack *stack, int x)
{
	int a;
	int b;

	a = -1;
	b = 0;
	while (++a < stack->size && stack->data[a] != x)
		b++;
	return (b);
}

void	sort_push(t_stack *stack_a, t_stack *stack_b, int size, int x)
{
	if (stack_b->size == 0 || size < 0)
		return ;
	while (stack_b->data[0] != x && stack_b->size != 1)
	{
		if (depth(stack_b, x) < stack_b->size / 2)
			PW("rb");
		else
			PW("rrb");
	}
	PW("pa");
}

void	csort_b(t_stack *stack_a, t_stack *stack_b, int size)
{
	int x;

	while (max(stack_b) > stack_a->data[0])
	{
		sort_push(stack_a, stack_b, size, max(stack_b));
		PW("sa");
	}
	while (stack_b->size > 0)
	{
		x = max(stack_b);
		if (move(stack_b, x - 1) < move(stack_b, x))
		{
			sort_push(stack_a, stack_b, size, x - 1);
			sort_push(stack_a, stack_b, size, x);
			if (stack_a->data[0] > stack_a->data[1])
				PW("sa");
		}
		else
			sort_push(stack_a, stack_b, size, x);
	}
}

int		csort(t_stack *stack_a, t_stack *stack_b, int size, int n)
{
	int i;
	int j;

	i = 1;
	while (i < n + 1)
	{
		j = 0;
		while ((j < size / n))
		{
			if (stack_a->data[0] <= (size / n) * i)
			{
				PW("pb");
				j++;
			}
			else
				PW("ra");
		}
		i++;
	}
	csort_b(stack_a, stack_b, size);
	return (0);
}
