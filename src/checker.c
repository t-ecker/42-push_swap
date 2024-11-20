/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tecker <tecker@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 12:29:01 by tomecker          #+#    #+#             */
/*   Updated: 2024/11/20 13:31:19 by tecker           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	use_operations(char *line, t_node **head_a, t_node **head_b)
{
	if (ft_strncmp(line, "rb", 3) == 0)
		rotate(head_b, '0');
	else if (ft_strncmp(line, "ra", 3) == 0)
		rotate(head_a, '0');
	else if (ft_strncmp(line, "sa", 3) == 0)
		swap(head_a, '0');
	else if (ft_strncmp(line, "sb", 3) == 0)
		swap(head_b, '0');
	else if (ft_strncmp(line, "rra", 4) == 0)
		rev_rotate(head_a, '0');
	else if (ft_strncmp(line, "rrb", 4) == 0)
		rev_rotate(head_b, '0');
	else if (ft_strncmp(line, "pa", 3) == 0)
		push(head_b, head_a, '0');
	else if (ft_strncmp(line, "pb", 3) == 0)
		push(head_a, head_b, '0');
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		ss(head_a, head_b);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		rrr(head_a, head_b);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		rr(head_a, head_b);
}

void	process_operations(char *buffer, t_node **head_a, t_node **head_b)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(buffer, '\n');
	while (i < get_size(split))
	{
		use_operations(split[i], head_a, head_b);
		i++;
	}
	free_double_array(split);
}

int	check_line(char *line)
{
	if (ft_strncmp(line, "rb\n", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "ra\n", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "sa\n", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "sb\n", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "rra\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "rrb\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "pa\n", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "pb\n", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "ss\n", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "rrr\n", 4) == 0)
		return (0);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		return (0);
	else
		return (1);
}

void	get_operations(char **final)
{
	char	*temp;
	char 	*tmp2;

	*final = malloc(1 * sizeof(char));
	if (!(*final))
		return ;
	*final[0] = 0;
	while (1)
	{
		temp = get_next_line(0);
		if (temp == NULL)
			break ;
		if (check_line(temp) == 1)
		{
			free(temp);
			free(*final);
			exitwitherror();
		}
		tmp2 = *final;
		*final = ft_strjoin(*final, temp);
		free(tmp2);
		free(temp);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*head_a;
	t_node	*head_b;
	char	*buffer;

	head_b = NULL;
	head_a = NULL;
	if (argc == 1)
		exit(1);
	check_input(argc, argv);
	create_a(argc, argv, &head_a);
	check_dupe(head_a);
	get_operations(&buffer);
	process_operations(buffer, &head_a, &head_b);
	if (check_sorted(head_a) == 1 && head_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(buffer);
	freelinkedlistandexit(head_a, '0');
	freelinkedlistandexit(head_b, '0');
	return (0);
}
