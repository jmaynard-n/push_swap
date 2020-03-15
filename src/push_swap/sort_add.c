/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:58:12 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/24 13:10:49 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack			*ft_getn(t_stack *stack, int n)
{
	t_stack *tmp;
	int		i;

	if (!stack || n < 0)
		return (stack);
	tmp = stack;
	i = 0;
	while (tmp && i < n)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

int				ft_check_med(int mid, t_stack *a, int len, int st)
{
	t_stack		*tmp;
	int			i;

	i = 0;
	tmp = a;
	if (st)
	{
		while (tmp && i <= len)
		{
			if (tmp->data < mid)
				return (1);
			tmp = tmp->next;
			i++;
		}
		return (0);
	}
	while (tmp && i <= len)
	{
		if (tmp->data > mid)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}
