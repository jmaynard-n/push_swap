/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_valid_stack.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 15:00:08 by jmaynard          #+#    #+#             */
/*   Updated: 2019/08/01 10:35:37 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int				ft_stack_len(t_stack *stack)
{
	int		n;
	t_stack	*tmp;

	tmp = stack;
	n = 0;
	if (!stack)
		return (0);
	while (tmp)
	{
		n++;
		tmp = tmp->next;
	}
	return (n);
}

static int		ft_valid(const char *av, int *flag)
{
	long long int	int_max;
	long long int	int_min;
	long long int	data;

	int_max = 2147483647;
	int_min = -2147483648;
	*flag = 1;
	if (!av)
	{
		*flag = 2;
		return (0);
	}
	data = ft_atoi_large(av, flag);
	if (ft_strstr(av, "-v") || ft_strstr(av, "-c"))
		*flag = 0;
	if (data > int_max || data < int_min)
		*flag = 0;
	return (data);
}

static int		ft_duplicate(t_stack *stack, int data)
{
	t_stack *tmp;

	tmp = stack;
	if (!stack)
		return (1);
	while (tmp)
	{
		if (tmp->data == data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static int		ft_del(char ***ptr)
{
	char	**str;
	int		i;

	str = *ptr;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	*ptr = NULL;
	return (0);
}

int				ft_create_stack(t_stack **stack, char **argv, int ac)
{
	int		data;
	char	**ptr;
	int		i;
	int		flag;

	while (--ac > 0)
	{
		i = 0;
		if (!(ptr = ft_strsplit(argv[ac], ' ')))
			return (0);
		while (ptr[i])
			i++;
		while (--i >= 0)
		{
			data = ft_valid(ptr[i], &flag);
			if (!flag)
				return (ft_del(&ptr));
			else if (!ft_duplicate(*stack, data))
				return (ft_del(&ptr));
			if (!ft_add(stack, data))
				return (ft_del(&ptr));
		}
		ft_del(&ptr);
	}
	return (1);
}
