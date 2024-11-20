/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 20:04:34 by tecker            #+#    #+#             */
/*   Updated: 2024/11/19 20:33:39 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	push(t_node **from, t_node **to, char c)
{
	t_node	*temp2;
	t_node	*temp1;

	if (*from == NULL)
		return ;
	temp1 = *from;
	temp2 = (*from)->next;
	temp1->next = *to;
	*to = temp1;
	*from = temp2;
	if (c == 'b')
		ft_putstr_fd("pa\n", 1);
	else if (c == 'a')
		ft_putstr_fd("pb\n", 1);
}
