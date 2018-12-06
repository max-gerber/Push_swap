/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 10:54:46 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/27 14:29:18 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		evaluate(t_stack *stack_a, t_stack *stack_b)
{
	int a;

	a = 0;
	if (stack_b->size)
		return (0);
	while (++a < stack_a->size)
		if (stack_a->data[a - 1] > stack_a->data[a])
			return (0);
	return (1);
}

int		valid_nbr(char *str, int i)
{
	int		a;
	char	*new;

	a = -1;
	new = ft_itoa(ft_atoi(str));
	while (str[++a])
		if (ft_strcmp(str, new))
			exit(write(2, "ERROR\n", 6));
	free(new);
	i ? free(str) : 0;
	return (ft_atoi(str));
}

void	valid_stack(t_stack stack)
{
	int	a;
	int	b;

	a = -1;
	while (++a < stack.size)
	{
		b = a;
		while (++b < stack.size)
			if (stack.data[a] == stack.data[b])
				exit(write(2, "ERROR\n", 6));
	}
}

int		*args(int *size, char **av)
{
	int		a;
	int		b;
	char	**argv;
	int		*temp;

	a = -1;
	(*size < 1) ? (exit(0)) : 0;
	if (*size > 1)
		temp = (int*)malloc(sizeof(int) * *size);
	else
	{
		argv = ft_strsplit(av[1], ' ');
		b = 0;
		while (argv[b])
			b++;
		*size = b;
		temp = (int*)malloc(sizeof(int) * b);
		while (++a < *size)
			temp[a] = valid_nbr(argv[a], 1);
		free(argv);
		return (norm(temp, *size));
	}
	while (++a < *size)
		temp[a] = valid_nbr(av[a + 1], 0);
	return (norm(temp, *size));
}

int		*norm(int *stack, int size)
{
	int a;
	int b;
	int *temp;

	temp = (int*)malloc(sizeof(int) * size);
	a = -1;
	while (++a < size)
	{
		temp[a] = stack[a];
		stack[a] = size;
	}
	a = -1;
	while (++a < size)
	{
		b = -1;
		while (++b < size)
			if (temp[a] < temp[b])
				stack[a]--;
	}
	free(temp);
	return (stack);
}
