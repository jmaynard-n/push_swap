/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:54:05 by jmaynard          #+#    #+#             */
/*   Updated: 2019/08/01 12:30:27 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_valid_pres(char *fmt, t_flags *param, va_list *arg)
{
	param->pres = 0;
	fmt++;
	if (*fmt == '*')
	{
		param->pres = va_arg(*arg, int);
		fmt++;
	}
	else
	{
		if (ft_isdigit(*fmt))
			param->pres = ft_atoi(fmt);
		while (ft_isdigit(*fmt))
			fmt++;
	}
	return (fmt);
}

void	ft_help_valid_flags(t_flags *param)
{
	int i;

	if ((ft_strchr(param->flags, '+') != NULL)
		&& (ft_strchr(param->flags, ' ') != NULL))
	{
		i = 0;
		while (param->flags[i] != '\0')
		{
			if (param->flags[i] == ' ')
				param->flags[i] = '+';
			i++;
		}
	}
	if ((ft_strchr(param->flags, '-') != NULL)
		&& (ft_strchr(param->flags, '0') != NULL))
	{
		i = 0;
		while (param->flags[i] != '\0')
		{
			if (param->flags[i] == '0')
				param->flags[i] = '-';
			i++;
		}
	}
}

int		ft_help_valid_flag(char *flags, char *fmt, t_flags *param)
{
	size_t	size;
	char	*tmp;

	while (ft_strchr(flags, *fmt) && (size = ft_strlen(param->flags) + 1))
	{
		if (!(tmp = (char *)ft_memalloc(size + 1)))
			return (0);
		ft_strcpy(tmp, param->flags);
		tmp[size - 1] = *fmt;
		ft_strdel(&(param->flags));
		if (!(param->flags = ft_strdup(tmp)))
			return (0);
		fmt++;
		ft_strdel(&tmp);
	}
	return (1);
}

char	*ft_valid_flag(char *flags, char *fmt, t_flags *param)
{
	size_t	size;

	size = 1;
	if (param->flags == NULL && ft_strchr(flags, *fmt))
	{
		if (!(param->flags = (char *)malloc((size + 1) * sizeof(char))))
			return (NULL);
		ft_memset(param->flags, '\0', size + 1);
		param->flags[0] = *fmt;
		fmt++;
	}
	if (!(ft_help_valid_flag(flags, fmt, param)))
		return (NULL);
	if (param->flags != NULL)
		ft_help_valid_flags(param);
	return (fmt);
}

char	*ft_flags(char *fmt, t_flags *param)
{
	char *flags;

	if (!(flags = ft_strdup("#0- +")))
		return (NULL);
	fmt = ft_valid_flag(flags, fmt, param);
	if ((param->flags != NULL) && (ft_strcmp(param->flags, "error") == 0))
	{
		ft_free_param(param);
		return (NULL);
	}
	ft_strdel(&flags);
	return (fmt);
}
