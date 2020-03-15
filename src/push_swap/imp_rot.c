/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imp_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 09:45:34 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 09:54:28 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int		ft_imp_rrot_h(char **str)
{
	char *beg;
	char *end;
	char *s;

	while ((s = ft_strstr(*str, "rrb\nrb\n")))
	{
		if (!(end = ft_strdup(s + 7)))
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

int				ft_imp_rrot(char **str)
{
	char *beg;
	char *end;
	char *s;

	while ((s = ft_strstr(*str, "rra\nra\n")))
	{
		if (!(end = ft_strdup(s + 7)))
			return (0);
		if (!(beg = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(s))))
			return (0);
		ft_strdel(str);
		if (!(*str = ft_strjoin(beg, end)))
			return (0);
		ft_strdel(&end);
		ft_strdel(&beg);
	}
	if (!(ft_imp_rrot_h(str)))
		return (0);
	return (1);
}

static int		ft_imp_rot_h(char **str)
{
	char *beg;
	char *end;
	char *s;

	while ((s = ft_strstr(*str, "\nrb\nrrb\n")))
	{
		if (!(end = ft_strdup(s + 7)))
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

int				ft_imp_rot(char **str)
{
	char *beg;
	char *end;
	char *s;

	while ((s = ft_strstr(*str, "\nra\nrra\n")))
	{
		if (!(end = ft_strdup(s + 7)))
			return (0);
		if (!(beg = ft_strsub(*str, 0, ft_strlen(*str) - ft_strlen(s))))
			return (0);
		ft_strdel(str);
		if (!(*str = ft_strjoin(beg, end)))
			return (0);
		ft_strdel(&end);
		ft_strdel(&beg);
	}
	if (!(ft_imp_rot_h(str)))
		return (0);
	return (1);
}
