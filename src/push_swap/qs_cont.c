/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qs_cont.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 17:25:22 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 11:27:45 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

#include <stdio.h>

static long int		ft_moving_d(int *left, int *right, int *rot, t_stack **b)
{
	int mid;

	*left = *right;
	*rot = 0;
	mid = ft_mediana(*b, 0, *right - 1);
	*right = 0;
	return (mid);
}

int					ft_qs_cont(t_stack **a, t_stack **b, int *right, char **str)
{
	int				left;
	long int		mid;
	t_stack			*last;
	int				rot;
	long int		x;

	if ((mid = ft_moving_d(&left, right, &rot, a)) == 2147483648)
		return (-1);
	while (ft_check_med(mid, *a, left - *right - rot, 1))
	{
		last = ft_getn(*a, ft_stack_len(*a) - 1);
		if ((ft_stack_len(*a) - 1 == (left - *right)) && last->data < mid)
			x = ft_move_last(a, b, mid, str);
		else
			x = ft_move_first(a, b, mid, str);
		if (x == -1)
			return (-1);
		(*right) += x;
		if (ft_check_med(mid, *a, left - *right - rot, 1))
			if ((x = ft_cut(a, mid, str, &rot)) == -1)
				return (-1);
	}
	return (rot);
}

int					ft_qs_down_cont(t_stack **b, t_stack **a,
								int *right, char **str)
{
	int			left;
	long int	mid;
	t_stack		*last;
	int			rot;
	long int	x;

	if ((mid = ft_moving_d(&left, right, &rot, b)) == 2147483648)
		return (-1);
	while (ft_check_med(mid, *b, left - *right - rot, 0))
	{
		last = ft_getn(*b, ft_stack_len(*b) - 1);
		if ((ft_stack_len(*b) - 1 == (left - *right)) && last->data > mid)
			x = ft_mv_last(b, a, mid, str);
		else
			x = ft_mv_first(b, a, mid, str);
		if (x == -1)
			return (-1);
		(*right) += x;
		if (ft_check_med(mid, *b, left - *right - rot, 0))
			if ((x = ft_cut_down(b, mid, str, &rot)) == -1)
				return (-1);
	}
	return (rot);
}
