/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:05:38 by tecker            #+#    #+#             */
/*   Updated: 2024/11/19 20:33:46 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	swap(t_node **head, char c)
{
	t_node	*temp1;
	t_node	*temp2;

	temp2 = (*head)->next->next;
	temp1 = *head;
	if (*head == NULL || (*head)->next == NULL)
		return ;
	*head = (*head)->next;
	(*head)->next = temp1;
	temp1->next = temp2;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **head_a, t_node **head_b)
{
	swap(head_a, '0');
	swap(head_b, '0');
}
