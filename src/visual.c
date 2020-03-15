/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 09:58:25 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/25 18:10:54 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_puta(t_stack *a, int flag)
{
	if (flag)
	{
		if (a)
			ft_printf("\x1b[36m%10d \x1b[0m| ", (a)->data);
		else
			ft_printf("%-10c | ", ' ');
	}
	else
	{
		if (a)
			ft_printf("%10d | ", (a)->data);
		else
			ft_printf("%-10c | ", ' ');
	}
}

void				ft_putb(t_stack *b, int flag)
{
	if (flag)
	{
		if (b)
			ft_printf("\x1b[33m%-10d\n\x1b[0m", (b)->data);
		else
			ft_printf("%-10c\n", ' ');
	}
	else
	{
		if (b)
			ft_printf("%-10d\n", (b)->data);
		else
			ft_printf("%-10c\n", ' ');
	}
}

static void			ft_putlst_col(t_stack *a, t_stack *b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	tmp1 = a;
	tmp2 = b;
	i = 0;
	ft_printf("\x1b[32m         STACK A | STACK B \x1b[0m\n");
	while (tmp1 || tmp2)
	{
		ft_printf("[\x1b[35m%4d\x1b[0m]", i);
		ft_puta(tmp1, 1);
		ft_putb(tmp2, 1);
		if (tmp1)
			tmp1 = tmp1->next;
		if (tmp2)
			tmp2 = tmp2->next;
		i++;
	}
}

static void			ft_putlst_white(t_stack *a, t_stack *b)
{
	t_stack	*tmp1;
	t_stack	*tmp2;
	int		i;

	tmp1 = a;
	tmp2 = b;
	i = 0;
	ft_printf("         STACK A | STACK B\n");
	while (tmp1 || tmp2)
	{
		ft_printf("[%4d]", i);
		ft_puta(tmp1, 0);
		ft_putb(tmp2, 0);
		if (tmp1)
			tmp1 = tmp1->next;
		if (tmp2)
			tmp2 = tmp2->next;
		i++;
	}
}

void				ft_putlst(t_stack *a, t_stack *b, int flag)
{
	if (flag == -1)
		return ;
	if (!flag)
		ft_putlst_white(a, b);
	else
		ft_putlst_col(a, b);
}
