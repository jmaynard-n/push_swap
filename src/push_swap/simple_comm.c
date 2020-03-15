/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_comm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 13:52:40 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/25 16:39:46 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int		ft_minimum(t_stack *stack, int len)
{
	int		i;
	int		min;
	int		p;
	t_stack	*tmp;

	i = 0;
	p = 0;
	min = stack->data;
	tmp = stack;
	while (tmp && i <= len)
	{
		if (tmp->data < min)
		{
			p = i;
			min = tmp->data;
		}
		i++;
		tmp = tmp->next;
	}
	return (p);
}

int		ft_max(t_stack *stack, int len)
{
	int		i;
	int		max;
	int		p;
	t_stack	*tmp;

	i = 0;
	p = 0;
	max = stack->data;
	tmp = stack;
	while (tmp && i <= len)
	{
		if (tmp->data > max)
		{
			p = i;
			max = tmp->data;
		}
		i++;
		tmp = tmp->next;
	}
	return (p);
}

char	*ft_simple_sort(t_stack **a, t_stack **b, int *len, int order)
{
	char	*str;
	int		x;

	if (!(str = (char *)ft_memalloc(1)))
		return (NULL);
	if (order)
		x = ft_down(a, b, len, &str);
	else
		x = ft_sup(a, b, len, &str);
	if (!x)
		return (NULL);
	return (str);
}

int		ft_stradd(char **str, char *new)
{
	char *tmp;

	if (!(tmp = ft_strjoin(*str, new)))
		return (0);
	ft_strdel(str);
	if (!(*str = ft_strdup(tmp)))
		return (0);
	ft_strdel(&tmp);
	return (1);
}
