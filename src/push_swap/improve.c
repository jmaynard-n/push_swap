/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 18:00:52 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 09:50:42 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		ft_imp_push_h(char **str)
{
	char *beg;
	char *end;
	char *s;

	while ((s = ft_strstr(*str, "pb\npa\n")))
	{
		if (!(end = ft_strdup(s + 6)))
			return (0);
		if (!(beg = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(s))))
			return (0);
		ft_strdel(str);
		if (!(*str = ft_strjoin(beg, end)))
			return (0);
		ft_strdel(&end);
		ft_strdel(&beg);
	}
	return (1);
}

static int		ft_imp_push(char **str)
{
	char *beg;
	char *end;
	char *s;

	while ((s = ft_strstr(*str, "pa\npb\n")))
	{
		if (!(end = ft_strdup(s + 6)))
			return (0);
		if (!(beg = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(s))))
			return (0);
		ft_strdel(str);
		if (!(*str = ft_strjoin(beg, end)))
			return (0);
		ft_strdel(&end);
		ft_strdel(&beg);
	}
	if (!(ft_imp_push_h(str)))
		return (0);
	return (1);
}

static int		ft_imp_swap(char **str)
{
	char *beg;
	char *end;
	char *s;

	while ((s = ft_strstr(*str, "sa\nsa\n")))
	{
		if (!(end = ft_strdup(s + 6)))
			return (0);
		if (!(beg = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(s))))
			return (0);
		ft_strdel(str);
		if (!(*str = ft_strjoin(beg, end)))
			return (0);
		ft_strdel(&end);
		ft_strdel(&beg);
	}
	return (1);
}

int				ft_improve(char **str)
{
	if (!(ft_imp_push(str)))
		return (0);
	if (!(ft_imp_rrot(str)))
		return (0);
	if (!(ft_imp_rot(str)))
		return (0);
	if (!(ft_imp_swap(str)))
		return (0);
	return (1);
}
