/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 13:05:44 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 10:25:35 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		try_rev(t_stack **a, int len, char **str)
{
	ft_revrot(a);
	if (ft_order(*a, len, 0))
	{
		if (!(ft_stradd(str, "rra\n")))
			return (0);
	}
	else
	{
		ft_rot(a);
		if (!(ft_stradd(str, "ra\n")))
			return (0);
		ft_rot(a);
	}
	return (1);
}

static int		ft_ch_top(t_stack **a, int len, char **str)
{
	t_stack *first;
	t_stack *sec;
	t_stack *last;

	if (*a == NULL)
		return (1);
	first = *a;
	sec = (*a)->next;
	last = ft_getn(*a, len);
	if (len >= 1 && first->data > last->data)
		if (!try_rev(a, len, str))
			return (0);
	if (ft_order(*a, len, 0))
		return (1);
	if (len >= 1 && first->data > sec->data)
	{
		ft_swap(a);
		if (!(ft_stradd(str, "sa\n")))
			return (0);
	}
	return (1);
}

static int		ft_get_place(t_stack **a, int place, char **str)
{
	int i;

	i = 0;
	if (place == 1 || (*a)->data > ((*a)->next)->data)
	{
		ft_swap(a);
		if (!(ft_stradd(str, "sa\n")))
			return (-1);
		if (ft_stack_len(*a) == 2 || ft_order(*a, ft_stack_len(*a) - 1, 0))
			return (1);
		return (1);
	}
	if (place <= (ft_stack_len(*a) - 1) / 2 && place != 0)
	{
		while (i < place)
		{
			if (!(ft_stradd(str, "ra\n")))
				return (-1);
			ft_rot(a);
			i++;
		}
		return (1);
	}
	return (0);
}

static int		ft_simp_h(t_stack **a, t_stack **b, char **str, int f)
{
	int	len;

	if (f == -1)
		return (0);
	ft_push(b, a);
	len = ft_stack_len(*a) - 1;
	if (!(ft_stradd(str, "pb\n")))
		return (0);
	if (!(ft_ch_top(a, len, str)))
		return (0);
	if (!(ft_simple(a, b, str)))
		return (0);
	ft_push(a, b);
	if (!(ft_stradd(str, "pa\n")))
		return (0);
	return (1);
}

int				ft_simple(t_stack **a, t_stack **b, char **str)
{
	int		place;
	int		len;
	int		i;
	int		f;

	len = ft_stack_len(*a) - 1;
	if (ft_order(*a, len, 0))
		return (1);
	if (!(ft_ch_top(a, len, str)))
		return (0);
	if (len == 1)
		return (1);
	place = ft_minimum(*a, len);
	if (!(f = ft_get_place(a, place, str)) && place != 0)
	{
		i = len;
		while (i >= place)
		{
			if (!(ft_stradd(str, "rra\n")))
				return (0);
			ft_revrot(a);
			i--;
		}
	}
	return (ft_simp_h(a, b, str, f));
}
