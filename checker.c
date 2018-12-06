/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/27 12:13:26 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/28 12:39:28 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		stack_a;
	t_stack		stack_b;
	int			size;
	char		*line;

	size = argc - 1;
	stack_a.data = args(&size, argv);
	stack_a.size = size;
	valid_stack(stack_a);
	stack_b.data = (int*)malloc(sizeof(int) * size);
	stack_b.size = 0;
	while (get_next_line(0, &line) && parse(line, &stack_a, &stack_b))
		ft_strdel(&line);
	write(2, evaluate(&stack_a, &stack_b) ? "OK\n" : "KO\n", 3);
	free(stack_a.data);
	free(stack_b.data);
	exit(0);
}
