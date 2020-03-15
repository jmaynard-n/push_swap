/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 16:01:12 by jmaynard          #+#    #+#             */
/*   Updated: 2019/08/01 12:29:11 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int				ft_order(t_stack *stack, int len, int ord)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	if (!stack)
		return (0);
	if (!ord)
		return (ft_check_order(stack, len));
	else
	{
		while (tmp->next && i < len)
		{
			if (tmp->data < (tmp->next)->data)
				return (0);
			tmp = tmp->next;
			i++;
		}
	}
	return (1);
}

static int		ft_log(t_stack **a, t_stack **b, char **str)
{
	int f;
	int len;

	len = ft_stack_len(*a) - 1;
	if (len < 0)
		return (0);
	if (ft_stack_len(*a) - 1 <= 5)
		f = ft_simple(a, b, str);
	else
		f = ft_qs(a, b, ft_stack_len(*a) - 1, str);
	return (f);
}

static void		ft_final(t_stack **a, t_stack **b, char **str)
{
	if (!(ft_improve(str)))
	{
		ft_strdel(str);
		ft_error(a, b);
	}
	ft_putstr(*str);
	ft_stackdel(a);
	ft_stackdel(b);
	ft_strdel(str);
}

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		*str;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		if (!(str = (char *)ft_memalloc(1)))
			ft_error(&a, &b);
		if (!(ft_create_stack(&a, av, ac)))
		{
			ft_strdel(&str);
			ft_error(&a, &b);
		}
		if (!ft_log(&a, &b, &str))
		{
			ft_strdel(&str);
			ft_error(&a, &b);
		}
		ft_final(&a, &b, &str);
	}
	return (0);
}
