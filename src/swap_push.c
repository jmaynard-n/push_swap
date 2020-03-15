/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:30:47 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/25 15:41:09 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	int		tmp;

	if (*stack != NULL)
	{
		tmp = (*stack)->data;
		(*stack)->data = ((*stack)->next)->data;
		((*stack)->next)->data = tmp;
	}
}

void	ft_push(t_stack **dest, t_stack **src)
{
	t_stack *s;
	t_stack *d;

	if (!(*src))
		return ;
	d = *dest;
	s = *src;
	if (!s)
		return ;
	(*src) = (*src)->next;
	s->next = d;
	*dest = s;
}
