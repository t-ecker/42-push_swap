/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:05:08 by tecker            #+#    #+#             */
/*   Updated: 2024/05/15 12:08:06 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_node **head, char c)
{
	t_node	*temp1;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	temp1 = *head;
	*head = (*head)->next;
	temp1->next = NULL;
	ft_lstadd_back(head, temp1);
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	rev_rotate(t_node **head, char c)
{
	t_node	*last;
	t_node	*secoundlast;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	last = *head;
	while (last->next != NULL)
	{
		secoundlast = last;
		last = last->next;
	}
	last->next = *head;
	*head = last;
	secoundlast->next = NULL;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}

void	rr(t_node **head_a, t_node **head_b)
{
	rotate(head_a, '0');
	rotate(head_b, '0');
}

void	rrr(t_node **head_a, t_node **head_b)
{
	rev_rotate(head_a, '0');
	rev_rotate(head_b, '0');
}
