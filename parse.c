/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:33:54 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/06 12:38:03 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse2(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "rra"))
		rrotate(stack_a);
	else if (!ft_strcmp(line, "rrb"))
		rrotate(stack_b);
	else if (!ft_strcmp(line, "rrr"))
	{
		rrotate(stack_a);
		rrotate(stack_b);
	}
	else
		exit(write(2, "ERROR\n", 6));
}

int		parse(char *line, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(line, "sa"))
		swap(stack_a);
	else if (!ft_strcmp(line, "sb"))
		swap(stack_b);
	else if (!ft_strcmp(line, "ss"))
	{
		swap(stack_a);
		swap(stack_b);
	}
	else if (!ft_strcmp(line, "pa"))
		push(stack_a, pop(stack_b));
	else if (!ft_strcmp(line, "pb"))
		push(stack_b, pop(stack_a));
	else if (!ft_strcmp(line, "ra"))
		rotate(stack_a);
	else if (!ft_strcmp(line, "rb"))
		rotate(stack_b);
	else if (!ft_strcmp(line, "rr"))
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else
		parse2(line, stack_a, stack_b);
	return (1);
}
