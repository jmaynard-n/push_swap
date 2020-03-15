/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 18:38:26 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/24 18:25:47 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rot(t_stack **stack)
{
	t_stack *head;
	t_stack *tail;

	if (!(*stack))
		return ;
	head = *stack;
	tail = *stack;
	(*stack) = (*stack)->next;
	while (tail->next)
		tail = tail->next;
	tail->next = head;
	head->next = NULL;
}

void	ft_revrot(t_stack **stack)
{
	t_stack *tail;
	t_stack *prev;

	if (!(*stack) || ft_stack_len(*stack) == 1)
		return ;
	tail = *stack;
	prev = tail;
	while (tail->next)
		tail = tail->next;
	while (prev->next != tail)
		prev = prev->next;
	prev->next = NULL;
	tail->next = *stack;
	(*stack) = tail;
}
