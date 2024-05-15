/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:01:36 by tecker            #+#    #+#             */
/*   Updated: 2024/05/15 13:52:25 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

// operations:
void	push(t_node **from, t_node **to, char c);
void	rotate(t_node **head, char c);
void	rev_rotate(t_node **head, char c);
void	rr(t_node **head_a, t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);
void	swap(t_node **head_a, char c);
void	ss(t_node **head_a, t_node **head_b);

//sort:
void	sort(t_node **head_a, t_node **head_b);
void	sort_3(t_node **head_a, char c);
void	sort_10(t_node **head_a, t_node **head_b);

//utils:

void	check_dupe(t_node *head, int argc);
void	create_a(int argc, char *argv[], t_node **head);
void	check_input(int argc, char *argv[]);

void	freelinkedlistandexit(t_node *head, char c);
void	exitwitherror(void);
void	free_double_array(char **array);
void	check_int(long i);
int		get_size(char **array);

int		check_sorted(t_node *head_a);
int		direction(t_node **base, int z);
void	smart_push(t_node **base, t_node **out, int z, char c);
void	sort_algo(t_node **head_a, t_node **head_b, int chunk_size, int i);
void	sort_b(t_node **head_a, t_node **head_b);

#endif