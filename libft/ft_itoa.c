/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgerber <mgerber@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 15:33:32 by mgerber           #+#    #+#             */
/*   Updated: 2018/08/27 11:46:53 by mgerber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

size_t		ft_intlen(int i)
{
	int		temp;
	size_t	n;

	n = 0;
	if (!i)
		return (0);
	temp = i;
	if (i < 0)
	{
		temp *= -1;
		n++;
	}
	while (temp > 0)
	{
		temp /= 10;
		n++;
	}
	return (n);
}

char		*ft_itoa(int i)
{
	char	*str;
	size_t	n;

	if (i == -2147483648)
		return (ft_strdup("-2147483648"));
	n = ft_intlen(i);
	if (!(str = ft_memalloc(n)))
		return (0);
	str[n] = '\0';
	if (i == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (i < 0)
	{
		str[0] = '-';
		i *= -1;
	}
	while (i)
	{
		str[--n] = i % 10 + '0';
		i /= 10;
	}
	return (str);
}
