/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 11:40:32 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 11:17:33 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				ft_cut(t_stack **a, const int mid, char **str, int *rot)
{
	t_stack *first;

	first = *a;
	while (first->data >= mid)
	{
		ft_rot(a);
		(*rot)++;
		if (!(ft_stradd(str, "ra\n")))
			return (-1);
		first = *a;
	}
	return (1);
}

static int		ft_merge(t_stack **a, t_stack **b, int right, char **str)
{
	while (right)
	{
		(right)--;
		ft_push(a, b);
		if (!(ft_stradd(str, "pa\n")))
			return (0);
	}
	return (1);
}

static int		ft_return(t_stack **a, int rot, char **str, int diff)
{
	int len;

	len = ft_stack_len(*a) - 1;
	while (rot && diff != len)
	{
		ft_revrot(a);
		rot--;
		if (!(ft_stradd(str, "rra\n")))
			return (0);
	}
	return (1);
}

static int		ft_else_qs(t_stack **a, t_stack **b, int *right, char **str)
{
	char *tmp;

	if (!(tmp = ft_simple_sort(a, b, right, 0)))
		return (0);
	if (!(ft_stradd(str, tmp)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}

int				ft_qs(t_stack **a, t_stack **b, int right, char **str)
{
	int			left;
	int			rot;

	rot = 0;
	if (right > 5)
	{
		left = right;
		if ((rot = ft_qs_cont(a, b, &right, str)) == -1)
			return (0);
		if (!(ft_return(a, rot, str, left - right)))
			return (0);
		if (!(ft_qs(a, b, left - right, str)))
			return (0);
		if (!(ft_qs_down(b, a, right - 1, str)))
			return (0);
		if (!(ft_merge(a, b, right, str)))
			return (0);
	}
	else if (!(ft_else_qs(a, b, &right, str)))
		return (0);
	return (1);
}
