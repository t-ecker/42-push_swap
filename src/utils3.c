/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 20:06:14 by tecker            #+#    #+#             */
/*   Updated: 2024/11/19 22:42:35 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	freelinkedlistandexit(t_node *head, char c)
{
	t_node	*temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	if (c == '1')
		write(STDERR_FILENO, "Error\n", 6);
	exit(0);
}

void	exitwitherror(void)
{
	write(STDERR_FILENO, "Error\n", 6);
	exit(1);
}

void	free_double_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	check_int(long i)
{
	if (i > INT_MAX || i < INT_MIN)
		exitwitherror();
}

int	get_size(char **array)
{
	int	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	return (length);
}

int	custom_lstsize(t_node *lst)
{
	int	counter;

	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	return (counter);
}

t_node	*custom_lstnew(int content)
{
	t_node	*ptr;

	ptr = malloc(sizeof(*ptr));
	if (!ptr)
		return (NULL);
	ptr->value = content;
	ptr->next = NULL;
	return (ptr);
}
t_node	*custom_lstlast(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	custom_lstadd_back(t_node **lst, t_node *new)
{
	if (*lst)
		custom_lstlast(*lst)->next = new;
	else
		*lst = new;
}
