/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 13:58:03 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/28 12:40:15 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		size;
	int		solved;

	size = argc - 1;
	stack_a.data = args(&size, argv);
	stack_a.size = size;
	valid_stack(stack_a);
	stack_b.data = (int*)malloc(sizeof(int) * size);
	stack_b.size = 0;
	solved = 1;
	if (size > 200)
		csort(&stack_a, &stack_b, size, 20);
	else if (size > 50)
		csort(&stack_a, &stack_b, size, 10);
	else
		while (solved)
			solved = size == 3 ? sort_3(&stack_a, &stack_b) : algo1(&stack_a,
			&stack_b);
	free(stack_a.data);
	free(stack_b.data);
	return (0);
}
