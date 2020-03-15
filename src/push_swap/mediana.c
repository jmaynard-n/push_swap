/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mediana.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 15:17:47 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/25 16:57:34 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void		ft_swap_el(int *arr, int *left, int *right)
{
	int tmp;

	tmp = arr[*left];
	arr[*left] = arr[*right];
	arr[*right] = tmp;
	(*left)++;
	(*right)--;
}

static void		ft_quiksort(int *arr, int first, int last)
{
	int left;
	int right;
	int mid;

	if (first < last)
	{
		left = first;
		right = last;
		mid = arr[(left + right) / 2];
		while (left <= right)
		{
			while (arr[left] < mid)
				left++;
			while (arr[right] > mid)
				right--;
			if (left <= right)
				ft_swap_el(arr, &left, &right);
		}
		if (right > 0)
			ft_quiksort(arr, first, right);
		if (left < last)
			ft_quiksort(arr, left, last);
	}
}

static int		ft_res(int *arr, int i)
{
	int res;

	if (i % 2 != 0)
		res = arr[i / 2];
	else
		res = (arr[(i + 1) / 2] + arr[(i - 1) / 2]) / 2;
	return (res);
}

long int		ft_mediana(t_stack *stack, int first, int last)
{
	t_stack *tmp;
	t_stack *end;
	int		*arr;
	int		i;
	int		res;

	tmp = ft_getn(stack, first);
	end = ft_getn(stack, last);
	if (!(arr = (int *)malloc(sizeof(int) * (last - first + 1))))
		return (2147483648);
	i = 0;
	while (tmp != end)
	{
		arr[i] = tmp->data;
		tmp = tmp->next;
		i++;
	}
	arr[i] = tmp->data;
	tmp = tmp->next;
	ft_quiksort(arr, 0, i);
	i += 2;
	res = ft_res(arr, i);
	free(arr);
	arr = NULL;
	return (res);
}
