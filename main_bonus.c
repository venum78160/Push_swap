/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:47:00 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/03/01 17:43:37 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "push_swap.h"

void	iforest2(char *str, t_info *i)
{
	if (ft_strncmp(str, "rra", 3) == 0)
		ft_rra(i, &i->list_a, 'j');
	else if (ft_strncmp(str, "rrb", 3) == 0)
		ft_rra(i, &i->list_b, 'j');
	else if (ft_strncmp(str, "rrr", 3) == 0)
	{
		ft_rra(i, &i->list_a, 'j');
		ft_rra(i, &i->list_b, 'j');
	}
	else if (ft_strnstr("pbpararbrrsasbss", str, 30) == NULL)
	{
		write(2, "KO\n", 3);
		exit(0);
	}
}

void	iforest(char *str, t_info *i)
{
	if (ft_strncmp(str, "pb", 3) == 0)
		ft_pa(i, &i->list_a, &i->list_b, 'j');
	else if (ft_strncmp(str, "pa", 3) == 0)
		ft_pa(i, &i->list_b, &i->list_a, 'j');
	else if (ft_strncmp(str, "ra", 3) == 0)
		ft_ra(i, &i->list_a, 'j');
	else if (ft_strncmp(str, "rb", 3) == 0)
		ft_ra(i, &i->list_b, 'j');
	else if (ft_strncmp(str, "rr", 3) == 0)
	{
		ft_ra(i, &i->list_a, 'j');
		ft_ra(i, &i->list_b, 'j');
	}
	else if (ft_strncmp(str, "sa", 3) == 0)
		ft_sa(i, &i->list_a, 'j');
	else if (ft_strncmp(str, "sb", 3) == 0)
		ft_sa(i, &i->list_b, 'j');
	else if (ft_strncmp(str, "ss", 3) == 0)
	{
		ft_sa(i, &i->list_b, 'j');
		ft_sa(i, &i->list_a, 'j');
	}
	iforest2(str, i);
}

void	ft_hub(t_info *i)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		iforest(str, i);
		free(str);
	}
}

int	main(int argc, char *argv[])
{
	t_info	i;

	if (argc > 1)
	{
		init(&i);
		verif(&i.list_a, argv);
		ft_hub(&i);
		ft_lstclear_ret(&i.ret);
		if (ft_if_sort(i.list_a) == 0 && ft_lstsize(i.list_b) == 0)
			write(2, "OK\n", 3);
		else
			write(2, "KO\n", 3);
	}
	return (0);
}
