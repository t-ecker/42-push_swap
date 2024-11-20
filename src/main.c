/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 19:54:45 by tecker            #+#    #+#             */
/*   Updated: 2024/11/19 20:33:18 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pos(t_node *head)
{
	t_node	*temp;
	t_node	*current;

	current = NULL;
	temp = NULL;
	current = head;
	while (current != NULL)
	{
		current->pos = 1;
		temp = head;
		while (temp != NULL)
		{
			if (temp->value < current->value)
				current->pos++;
			temp = temp->next;
		}
		current = current->next;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;

	head_b = NULL;
	head_a = NULL;
	check_input(argc, argv);
	create_a(argc, argv, &head_a);
	check_dupe(head_a);
	pos(head_a);
	sort(&head_a, &head_b);
	freelinkedlistandexit(head_a, '0');
	freelinkedlistandexit(head_b, '0');
	return (0);
}
