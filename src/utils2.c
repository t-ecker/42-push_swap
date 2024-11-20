/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:59:56 by tecker            #+#    #+#             */
/*   Updated: 2024/11/19 22:40:25 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sorted(t_node *head_a)
{
	t_node	*current;

	current = head_a;
	if (head_a == NULL)
		return (1);
	while (current->next != NULL)
	{
		if (current->value >= current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	direction(t_node **base, int z)
{
	int		half;
	int		index;
	t_node	*current;

	index = 1;
	half = custom_lstsize(*base) / 2;
	current = *base;
	while (current != NULL && current->value != z)
	{
		current = current->next;
		index++;
	}
	if (half >= index)
		return (1);
	return (0);
}

void	smart_push(t_node **base, t_node **out, int z, char c)
{
	if ((*base)->value == z)
		push(base, out, c);
	else if ((*base)->next->value == z)
	{
		swap(base, c);
		push(base, out, c);
	}
	else
	{
		if (direction(base, z))
		{
			while ((*base)->value != z)
				rotate(base, c);
		}
		else
		{
			while ((*base)->value != z)
				rev_rotate(base, c);
		}
		push(base, out, c);
	}
}

void	sort_algo(t_node **head_a, t_node **head_b, int chunk_size, int i)
{
	int			chunk;
	t_node		*current;
	t_node		*next_node;
	static int	j = 1;

	chunk = (i + 1) * chunk_size;
	current = *head_a;
	while (current != NULL)
	{
		next_node = current->next;
		if (current->pos <= j)
		{
			smart_push(head_a, head_b, current->value, 'a');
			rotate(head_b, 'b');
			j++;
		}
		else if (current->pos <= j + chunk)
		{
			smart_push(head_a, head_b, current->value, 'a');
			j++;
		}
		current = next_node;
	}
}

void	sort_b(t_node **head_a, t_node **head_b)
{
	int		max;
	t_node	*current;

	while (custom_lstsize(*head_b) > 0)
	{
		max = INT_MIN;
		current = *head_b;
		while (current != NULL)
		{
			if (current->value > max)
				max = current->value;
			current = current->next;
		}
		smart_push(head_b, head_a, max, 'b');
	}
}
