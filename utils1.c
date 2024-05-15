/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:54:26 by tecker            #+#    #+#             */
/*   Updated: 2024/05/15 11:53:39 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_dupe(t_node *head)
{
	t_node	*temp;
	t_node	*current;

	current = NULL;
	temp = NULL;
	current = head;
	while (current != NULL)
	{
		temp = head;
		while (temp != NULL)
		{
			if ((temp->value == current->value && temp != current)
				|| (current->value < INT_MIN) || (current->value > INT_MAX))
			{
				write(STDERR_FILENO, "Error\n", 6);
				freelinkedlistandexit(head);
			}
			temp = temp->next;
		}
		current = current->next;
	}
}

void	create_a(int argc, char *argv[], t_node **head)
{
	t_node	*new;
	char	**split;
	int		i;

	i = -1;
	if (argc != 2)
	{
		while (++i < argc - 1)
		{
			check_int(ft_atoi(argv[i + 1]));
			new = ft_lstnew(ft_atoi(argv[i + 1]));
			ft_lstadd_back(head, new);
		}
	}
	else
	{
		split = ft_split(argv[1], ' ');
		while (++i < get_size(split))
		{
			check_int(ft_atoi(split[i]));
			new = ft_lstnew(ft_atoi(split[i]));
			ft_lstadd_back(head, new);
		}
		free_double_array(split);
	}
}

void	check_input(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (argc < 2 || argv[i][0] == '\0')
			exitwitherror();
		j = 0;
		while (argv[i][j])
		{
			if ((((argv[i][j] < '0') || (argv[i][j] > '9'))
					&& (argv[i][j] != ' ')) || (argv[i][j] == ' ' && argc != 2))
			{
				if (!(argv[i][j] == '-'
					&& (argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9')))
					exitwitherror();
			}
			if ((argv[i][j] == ' ') && (argv[i][j + 1] == ' '))
				exit(0);
			j++;
		}
		if ((argv[i][ft_strlen(argv[i]) - 1] == ' ') || (argv[i][0] == ' '))
			exit(0);
	}
}
