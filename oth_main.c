/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   oth_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:21:36 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/03/01 17:06:42 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verif(t_list **list, char **argv)
{
	int	n;
	int	*tab;

	n = 0;
	while (argv[++n])
		crea_lst(list, argv[n]);
	tab = crea_tabi(list);
	sort_tab(tab, ft_lstsize(*list));
	if (find_dup(tab, ft_lstsize(*list)) == 1)
		ft_exit(tab);
	free(tab);
}

int	adclst(t_list *list)
{
	int	ret;

	ret = 0;
	if (list)
	{
		while (list)
		{
			ret = ret + list->content;
			list = list->next;
		}
	}
	return (ret);
}

void	ft_brain(t_info *i)
{
	t_list	*tete;

	tete = i->list_a;
	while (ft_if_sort(i->list_a) == 1 || ft_lstsize(i->list_b) != 0)
	{
		if (i->first > 0)
			ft_firtsort(i, tete->content);
		else if (i->second > 0)
			ft_second_step(i, tete->content);
		else if (i->third > 0)
			ft_third_step(i, tete->content);
		if (ft_if_sort(i->list_a) == 1 || ft_lstsize(i->list_b) != 0)
			swap_tete(i, &tete);
	}
}

void	crea_lst_inter(t_info *i, t_list *lst, int count)
{
	t_list	*list;

	list = lst;
	while (count > 0)
	{
		ft_lstadd_back(&i->temp, ft_lstnew(list->content));
		count--;
		list = list->next;
	}
}
