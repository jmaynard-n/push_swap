/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 09:37:29 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 11:21:13 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				ft_cut_down(t_stack **b, const int mid, char **str, int *rot)
{
	t_stack *first;

	first = *b;
	while (first->data <= mid)
	{
		ft_rot(b);
		(*rot)++;
		if (!(ft_stradd(str, "rb\n")))
			return (-1);
		first = *b;
	}
	return (1);
}

static int		ft_merge_down(t_stack **a, t_stack **b, int right, char **str)
{
	while (right)
	{
		(right)--;
		ft_push(b, a);
		if (!(ft_stradd(str, "pb\n")))
			return (0);
	}
	return (1);
}

static int		ft_return_down(t_stack **b, int rot, char **str, int diff)
{
	int len;

	len = ft_stack_len(*b) - 1;
	while (rot && diff != len)
	{
		ft_revrot(b);
		rot--;
		if (!(ft_stradd(str, "rrb\n")))
			return (0);
	}
	return (1);
}

static int		ft_else_qsd(t_stack **b, t_stack **a, int *right, char **str)
{
	char *tmp;

	if (!(tmp = ft_simple_sort(b, a, right, 1)))
		return (0);
	if (!(ft_stradd(str, tmp)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

int				ft_qs_down(t_stack **b, t_stack **a, int right, char **str)
{
	int		left;
	int		rot;

	rot = 0;
	if (right > 5)
	{
		left = right;
		if ((rot = ft_qs_down_cont(b, a, &right, str)) == -1)
			return (0);
		if (!(ft_return_down(b, rot, str, left - right)))
			return (0);
		if (!(ft_qs(a, b, right - 1, str)))
			return (0);
		if (!(ft_qs_down(b, a, left - right, str)))
			return (0);
		if (!(ft_merge_down(a, b, right, str)))
			return (0);
	}
	else if (!ft_else_qsd(b, a, &right, str))
		return (0);
	return (1);
}
