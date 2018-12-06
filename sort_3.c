/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 09:39:52 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/27 14:30:19 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#	define PW(s) write(parse(s,stack_a,stack_b),CONCAT(s,"\n"),ft_strlen(s)+1)

int	sort_3(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->data[0] < stack_a->data[1] && stack_a->data[1] <
	stack_a->data[2])
		return (0);
	if (stack_a->data[0] < stack_a->data[2])
		return (PW("sa"));
	if (stack_a->data[0] > stack_a->data[1])
		return (PW("ra"));
	return (PW("rra"));
}
