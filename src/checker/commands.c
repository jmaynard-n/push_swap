/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 17:53:28 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/24 09:52:39 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		ft_s_com(const char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "sa"))
		ft_swap(a);
	else if (!ft_strcmp(line, "sb"))
		ft_swap(b);
	else if (!ft_strcmp(line, "ss"))
	{
		ft_swap(a);
		ft_swap(b);
	}
	else
		return (0);
	return (1);
}

static int		ft_p_com(const char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "pa"))
		ft_push(a, b);
	else if (!ft_strcmp(line, "pb"))
		ft_push(b, a);
	else
		return (0);
	return (1);
}

static int		ft_r_com(const char *line, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(line, "ra"))
		ft_rot(a);
	else if (!ft_strcmp(line, "rb"))
		ft_rot(b);
	else if (!ft_strcmp(line, "rr"))
	{
		ft_rot(a);
		ft_rot(b);
	}
	else if (!ft_strcmp(line, "rra"))
		ft_revrot(a);
	else if (!ft_strcmp(line, "rrb"))
		ft_revrot(b);
	else if (!ft_strcmp(line, "rrr"))
	{
		ft_revrot(a);
		ft_revrot(b);
	}
	else
		return (0);
	return (1);
}

int				ft_valid_command(const char *line, t_stack **a, t_stack **b)
{
	if (ft_s_com(line, a, b))
		return (1);
	else if (ft_p_com(line, a, b))
		return (1);
	else if (ft_r_com(line, a, b))
		return (1);
	return (0);
}
