/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_down.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:15:03 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 11:18:11 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		ft_get(int place, t_stack **a, t_stack **b, char **str)
{
	int i;

	i = 0;
	while (i < place)
	{
		if (!(ft_stradd(str, "rb\n")))
			return (0);
		ft_rot(a);
		i++;
	}
	ft_push(b, a);
	if (!(ft_stradd(str, "pa\n")))
		return (0);
	i = 0;
	while (i < place)
	{
		if (!(ft_stradd(str, "rrb\n")))
			return (0);
		ft_revrot(a);
		i++;
	}
	return (1);
}

static int		ft_place_h(t_stack **a, t_stack **b, char **str)
{
	ft_swap(a);
	ft_push(b, a);
	if (!(ft_stradd(str, "sb\npa\n")))
		return (-1);
	return (1);
}

static int		ft_place(t_stack **a, t_stack **b, int len, char **str)
{
	int place;

	place = ft_max(*a, len);
	if (place == 0)
	{
		if (!(ft_stradd(str, "pa\n")))
			return (-1);
		ft_push(b, a);
		return (1);
	}
	else if (place == len && len == ft_stack_len(*a) - 1)
	{
		if (!(ft_stradd(str, "rrb\npa\n")))
			return (-1);
		ft_revrot(a);
		ft_push(b, a);
		return (1);
	}
	else if (place == 1)
		return (ft_place_h(a, b, str));
	return (0);
}

static int		ft_swapit(t_stack **a, char **str, int len)
{
	t_stack *first;
	t_stack *sec;

	first = *a;
	sec = (*a)->next;
	if (len >= 1 && first->data < sec->data)
	{
		ft_swap(a);
		if (!(ft_stradd(str, "sb\n")))
			return (-1);
	}
	return (1);
}

int				ft_down(t_stack **a, t_stack **b, int *len, char **str)
{
	int		place;
	int		f;

	if (ft_order(*a, *len, 1))
		return (1);
	place = ft_max(*a, *len);
	if (!(f = ft_place(a, b, *len, str)))
	{
		if (!(ft_get(place, a, b, str)))
			return (0);
	}
	else if (f == -1)
		return (0);
	(*len)--;
	if (ft_swapit(a, str, *len) == -1)
		return (0);
	if (!ft_down(a, b, len, str))
		return (0);
	ft_push(a, b);
	if (!(ft_stradd(str, "pb\n")))
		return (0);
	return (1);
}
