/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaynard <jmaynard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 14:40:57 by jmaynard          #+#    #+#             */
/*   Updated: 2019/07/26 11:14:15 by jmaynard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"

typedef struct	s_stack
{
	int					data;
	struct s_stack		*next;
}				t_stack;

/*
**	ft_atoi_large.c
*/
long long int	ft_atoi_large(const char *str, int *flag);

/*
** commands.c
*/
int				ft_valid_command(const char *line, t_stack **a, t_stack **b);

/*
** mediana.c
*/
long int		ft_mediana(t_stack *stack, int first, int last);

/*
** push_swap.c
*/
int				ft_order(t_stack *stack, int len, int ord);

/*
** simple.c
*/
int				ft_simple(t_stack **a, t_stack **b, char **str);

/*
** simple_down.c
*/
int				ft_down(t_stack **a, t_stack **b, int *len, char **str);

/*
** simple_up.c
*/
int				ft_sup(t_stack **a, t_stack **b, int *len, char **str);

/*
** simple_comm.c
*/
int				ft_minimum(t_stack *stack, int len);
int				ft_max(t_stack *stack, int len);
int				ft_stradd(char **str, char *new);
char			*ft_simple_sort(t_stack **a, t_stack **b, int *len, int order);

/*
** improve.c
*/
int				ft_improve(char **str);

/*
** imp_rot.c
*/
int				ft_imp_rrot(char **str);
int				ft_imp_rot(char **str);

/*
** stack.c
*/
int				ft_add(t_stack **stack, int data);
int				ft_check_order(t_stack *stack, int len);
void			ft_stackdel(t_stack **stack);
void			ft_error(t_stack **a, t_stack **b);

/*
** create_valid_stack.c
*/
int				ft_create_stack(t_stack **stack, char **argv, int ac);
int				ft_stack_len(t_stack *stack);

/*
** swap.c
*/
void			ft_swap(t_stack **stack);
void			ft_push(t_stack **dest, t_stack **src);

/*
** rotate.c
*/
void			ft_rot(t_stack **stack);
void			ft_revrot(t_stack **stack);

/*
** sort_a.c
*/
int				ft_qs(t_stack **a, t_stack **b, int right, char **str);
int				ft_cut(t_stack **a, const int mid, char **str, int *rot);

/*
** sort_b.c
*/
int				ft_qs_down(t_stack **b, t_stack **a, int right, char **str);
int				ft_cut_down(t_stack **b, const int mid, char **str, int *rot);

/*
** qs_cont.c
*/
int				ft_qs_cont(t_stack **a, t_stack **b, int *right, char **str);
int				ft_qs_down_cont(t_stack **b, t_stack **a,
								int *right, char **str);
/*
** sort_ad.c
*/
t_stack			*ft_getn(t_stack *stack, int n);
int				ft_check_med(int mid, t_stack *a, int len, int st);

/*
** sort_move.c
*/
int				ft_mv_first(t_stack **b, t_stack **a,
							const int mid, char **str);
int				ft_mv_last(t_stack **b, t_stack **a, const int mid, char **str);
int				ft_move_first(t_stack **a, t_stack **b,
							const int mid, char **str);
int				ft_move_last(t_stack **a, t_stack **b,
							const int mid, char **str);

/*
** visual.c
*/
void			ft_putlst(t_stack *a, t_stack *b, int flag);
void			ft_puta(t_stack *a, int flag);
void			ft_putb(t_stack *b, int flag);

#endif
