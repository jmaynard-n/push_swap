/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:08:13 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/25 15:32:15 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void				ft_error(t_stack **a, t_stack **b)
{
	ft_putendl_fd("Error", 2);
	ft_stackdel(a);
	ft_stackdel(b);
	exit(EXIT_FAILURE);
}

static t_stack		*ft_new(int data)
{
	t_stack *tmp;

	if (!(tmp = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	return (tmp);
}

int					ft_add(t_stack **stack, int data)
{
	t_stack *tmp;

	if (!(*stack))
	{
		if (!(*stack = ft_new(data)))
			return (0);
	}
	else
	{
		if (!(tmp = ft_new(data)))
			return (0);
		tmp->next = *stack;
		(*stack) = tmp;
	}
	return (1);
}

void				ft_stackdel(t_stack **stack)
{
	t_stack *tmp;

	if (!stack && !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

int					ft_check_order(t_stack *stack, int len)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	while (tmp->next && i < len)
	{
		if (tmp->data > (tmp->next)->data)
			return (0);
		tmp = tmp->next;
		i++;
	}
	return (1);
}
