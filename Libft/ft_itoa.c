/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:53:34 by vl-hotel          #+#    #+#             */
/*   Updated: 2021/10/28 12:10:49 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_rev_int_tab(char *tab)
{
	int	n;
	int	tmp;
	int	size;

	size = ft_strlen(tab);
	n = 0;
	while (n < size / 2)
	{
		tmp = tab[n];
		tab[n] = tab [size - 1 - n];
		tab [size - 1 - n] = tmp;
		n++;
	}
}

static int	ft_positif(long int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static int	ft_intlen(long int n)
{
	long int	size;

	if (ft_positif(n) == 1)
		n *= -1;
	size = 1;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long int	k;

	i = 0;
	k = n;
	res = ft_calloc(sizeof(char), (ft_intlen(k) + 1 + ft_positif(k)));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (ft_positif(k) == 1)
	{
		res[ft_intlen(k)] = '-';
		k *= -1;
	}
	while (k > 0)
	{
		res[i++] = (k % 10) + 48;
		k = k / 10;
	}
	ft_rev_int_tab(res);
	return (res);
}
