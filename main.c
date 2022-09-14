/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:54:25 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/02/28 16:22:15 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_info	i;
	int		count;

	if (argc > 1)
	{
		init(&i);
		verif(&i.list_a, argv);
		ft_brain(&i);
		count = 10000;
		while (--count > 0 && ft_lstsize_ret(i.ret) > 8)
			lst_change_rt_under(&i.ret);
		print_list_rt(i.ret);
		ft_lstclear(&i.list_a);
		ft_lstclear(&i.list_b);
		ft_lstclear_ret(&i.ret);
		ft_lstclear(&i.temp2);
		ft_lstclear(&i.temp);
	}
	else
		return (1);
	return (0);
}
