/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:01:20 by tecker            #+#    #+#             */
/*   Updated: 2024/05/14 20:22:32 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100(t_node **head_a, t_node **head_b, int size)
{
	int	chunk_size;
	int	i;

	chunk_size = (size / 8);
	i = -1;
	while (++i < 7)
	{
		sort_algo(head_a, head_b, chunk_size, i);
	}
	sort_10(head_a, head_b);
	sort_b(head_a, head_b);
}

void	sort_big(t_node **head_a, t_node **head_b, int size)
{
	int	chunk_size;
	int	i;

	chunk_size = (size / 15);
	i = -1;
	while (++i < 14)
		sort_algo(head_a, head_b, chunk_size, i);
	sort_10(head_a, head_b);
	sort_b(head_a, head_b);
}

void	sort_10(t_node **head_a, t_node **head_b)
{
	int		min;
	t_node	*current;
	int		size_b;

	if (*head_a == NULL)
		return ;
	size_b = ft_lstsize(*head_b);
	while (ft_lstsize(*head_a) > 3)
	{
		min = INT_MAX;
		current = *head_a;
		while (current != NULL)
		{
			if (current->value < min)
				min = current->value;
			current = current->next;
		}
		smart_push(head_a, head_b, min, 'a');
	}
	sort_3(head_a, 'a');
	while (ft_lstsize(*head_b) > size_b)
		push(head_b, head_a, 'b');
}

void	sort_3(t_node **head, char c)
{
	while (check_sorted(*head) != 1)
	{
		if ((*head)->next->pos > (*head)->next->next->pos
			&& (*head)->next->pos > (*head)->pos)
			rev_rotate(head, c);
		else if ((*head)->pos > (*head)->next->next->pos)
			rotate(head, c);
		if ((*head)->pos > (*head)->next->pos)
			swap(head, c);
	}
}

void	sort(t_node **head_a, t_node **head_b)
{
	int	size;

	if (check_sorted(*head_a) == 1)
		return ;
	size = ft_lstsize(*head_a);
	if (size == 2)
	{
		if ((*head_a)->pos > (*head_a)->next->pos)
			swap(head_a, 'a');
	}
	else if (size <= 10)
		sort_10(head_a, head_b);
	else if (size > 10 && size <= 100)
		sort_100(head_a, head_b, size);
	else if (size > 100)
		sort_big(head_a, head_b, size);
}
