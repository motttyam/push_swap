/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktsukamo <ktsukamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 15:05:19 by ktsukamo          #+#    #+#             */
/*   Updated: 2024/06/09 21:20:35 by ktsukamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*previous;
	struct s_stack	*next;
}					t_stack;

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10
# define END -1

typedef struct s_ans
{
	int				ans[13];
	int				save[13];
}					t_ans;

typedef struct s_position
{
	int				top;
	int				mid;
	int				last;
}					t_position;

typedef struct s_sort_params
{
	int				piv_h;
	int				piv_l;
	int				l;
	int				m;
	int				s;
	int				i;
}					t_sort_params;

// 1_format_one_arg.c
int					*format_one_arg(char *str, int *arrlen);
void				boxfree(char **box);
int					*box_to_arr(char **box, int *arrlen);

// 1_format_args.c
int					*format_args(char **box, int *arrlen);

// 2_arr2circular.c
t_stack				*arr2circular(int *arr, int arrlen);
t_stack				*arr_value2circular(int *arr, int arrlen);
void				link2circular(t_stack *list);
void				arr_value2compact_range(int *arr, int *cp_arr, int arrlen);

// 3_push_swap.c
void				push_swap(t_stack *stack_a, t_stack *stack_b);

// 4_sort_few.c
void				sort_few(t_stack *stack_a, t_stack *stack_b);
void				search_dfs(t_stack *stack_a, t_stack *stack_b, t_ans *ans,
						int move);
void				save_ans(t_ans *ans, int move);

// 4_sort_left.c
void				sort_left(t_stack **a, t_stack **b, int len, int i);
void				sort_left_lms(t_stack **a, t_stack **b,
						t_sort_params *left);
void				partition_left(t_stack **a, t_stack **b, int len,
						t_sort_params *left);

// 5_sort_right.c
void				sort_right(t_stack **a, t_stack **b, int len, int i);
void				sort_right_lms(t_stack **a, t_stack **b,
						t_sort_params *right);
void				partition_right(t_stack **a, t_stack **b,
						t_sort_params *right, int len);

// funcs //////////////////////////////////////////////////////////////////

// funcs_check.c
int					isnum(char *str);
int					is_unique_num(int *arr, int arrlen);
int					is_sorted(t_stack *stack_a);

// funcs_lens_cpys.c
int					ft_boxlen(char **box);
int					*arrcpy(int *arr, int arrlen);

// funcs_lsts.c
int					ft_lstsize(t_stack *list);
t_stack				*ft_lstnew(int content);
t_stack				*ft_lstlast(t_stack *list);
void				ft_lstclear(t_stack **a, t_stack **b);
void				ft_lstadd_back(t_stack **list, t_stack *new);

// funcs_push_swap_rotate_reverse.c
void				swap(t_stack *stack);
void				push(t_stack **src, t_stack **dst);
void				r_rotate(t_stack **stack);
void				rotate(t_stack **stack);

// funcs_print_sprrr.c
void				sa(t_stack **a);
void				sb(t_stack **b);
void				pa(t_stack **a, t_stack **b);
void				pb(t_stack **a, t_stack **b);
void				ra(t_stack **a);
void				rb(t_stack **b);
void				rra(t_stack **a);
void				rrb(t_stack **b);

// funcs_split.c
char				**ft_split(char const *s, char c);
int					ft_split2(char **dest, int j, const char *s, int len);
int					word_count(const char *s, char c);

// funcs_atoi.c
int					ft_atoi(const char *str);
void				printerror(void);

// funcs_sort_few.c
void				move_cmd(t_stack *a, t_stack *b, int cmd, int *flag);
void				remove_cmd(t_stack *a, t_stack *b, int cmd, int flag);
void				print_cmd(t_ans *ans, t_stack **a, t_stack **b);
void				choose_cmd(int i, t_ans *ans, t_stack **a, t_stack **b);

// funcs_sort_left.c
void				sort_l_l(t_stack **a, t_stack **b, int len);
void				sort_l_l_three(t_stack **a, t_stack **b, t_position pos);
void				sort_l_m(t_stack **a, t_stack **b, int len);
void				sort_l_s(t_stack **a, t_stack **b, int len);

// funcs_sort_right.c
void				sort_r_l(t_stack **a, t_stack **b, int len);
void				sort_r_m(t_stack **a, t_stack **b, int len);
void				sort_r_s(t_stack **a, t_stack **b, int len);
void				right_s_three(t_stack **a, t_stack **b, t_position pos);

// funcs_sort_tools.c
void				bubble_sort(int *arr, int arrlen);
int					max_lim(t_stack *stack, int len);
int					min_lim(t_stack *stack, int len);
t_sort_params		init_params(t_stack **stack, int len, int i);

// tests //////////////////////////////////////////////////////////////////////
void				print_stack(t_stack *stack);

#endif