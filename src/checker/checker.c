/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:43:15 by jmaynard          #+#    #+#             */
/*   Updated: 2019/08/01 12:55:11 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		ft_fin(t_stack *a, t_stack *b)
{
	if (b != NULL)
		return (0);
	if (!ft_check_order(a, ft_stack_len(a) - 1))
		return (0);
	return (1);
}

static void		ft_alg(t_stack **a, t_stack **b, int flag)
{
	char	*line;
	int		res;

	line = NULL;
	if (ft_stack_len(*a) - 1 < 0)
		return ;
	ft_putlst(*a, *b, flag);
	while ((res = get_next_line(0, &line)) > 0)
	{
		if (!ft_valid_command(line, a, b))
		{
			ft_stackdel(a);
			ft_stackdel(b);
			ft_error(a, b);
		}
		if (flag > -1)
			ft_printf("Exec : %s\n", line);
		ft_strdel(&line);
		ft_putlst(*a, *b, flag);
	}
	if (ft_fin(*a, *b))
		ft_putendl("OK");
	else
		ft_putendl("KO");
	ft_strdel(&line);
}

static int		ft_check_flag(char **av)
{
	int flag;

	flag = -1;
	if (ft_strstr(av[1], "-c"))
		flag = 1;
	else if (ft_strstr(av[1], "-v"))
		flag = 0;
	if (flag > -1)
		ft_memset(av[1], ' ', 2);
	return (flag);
}

int				main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	int			flag;

	a = NULL;
	b = NULL;
	if (ac == 1)
		exit(EXIT_SUCCESS);
	else
	{
		flag = ft_check_flag(av);
		if (!(ft_create_stack(&a, av, ac)))
			ft_error(&a, &b);
		if ((!ft_strcmp(av[1], "-v") || !ft_strcmp(av[1], "-c")) && ac == 2)
			return (0);
		ft_alg(&a, &b, flag);
	}
	ft_stackdel(&a);
	ft_stackdel(&b);
	return (0);
}
