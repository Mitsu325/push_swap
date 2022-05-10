/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:03:23 by pmitsuko          #+#    #+#             */
/*   Updated: 2022/05/09 05:44:09 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* -------------------------------------------------------------------------- **
** FUNCTION: remove_first_node
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** The first node is removed from the last. If the last contains only one node,
** the last will be NULL.
** PARAMETERS:
** #last. The t_list struct.
** RETURN VALUES:
** Returns the first node removed from last.
** -------------------------------------------------------------------------- */
static t_list	*remove_first_node(t_list **last)
{
	t_list	*first;

	first = (*last)->next;
	if (*last == (*last)->next)
		*last = NULL;
	else
		(*last)->next = (*last)->next->next;
	return (first);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: insert_first_node
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Add the node to the top of the list.
** PARAMETERS:
** #last. The t_list struct.
** #node. The t_list struct. Push node.
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
static void	insert_first_node(t_list **last, t_list *node)
{
	if (*last == NULL)
	{
		node->next = node;
		*last = node;
	}
	else
	{
		node->next = (*last)->next;
		(*last)->next = node;
	}
}

/* -------------------------------------------------------------------------- **
** FUNCTION: push
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Take the first element at the top of last_from and put it at the top of
** last_to. Do nothing if last_from is empty.
** PARAMETERS:
** #last_to. The t_list struct. Included at the top of the list.
** #last_from. The t_list struct. Removed the first element from the list.
** RETURN VALUES:
** -
** -------------------------------------------------------------------------- */
void	push(t_list **last_to, t_list **last_from)
{
	t_list	*first;

	if (*last_from == NULL)
		return ;
	first = remove_first_node(last_from);
	insert_first_node(last_to, first);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: pa
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Take the first element at the top of b and put it at the top of a. It must
** display "pa".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	pa(t_stack *stack)
{
	push(&stack->last_a, &stack->last_b);
	ft_putstr_fd("pa\n", 1);
	stack->size_a++;
	stack->size_b--;
	return (SUCCESS);
}

/* -------------------------------------------------------------------------- **
** FUNCTION: pb
** -------------------------------------------------------------------------- **
** DESCRIPTION:
** Take the first element at the top of a and put it at the top of b. It must
** display "pb".
** PARAMETERS:
** #stack. The t_stack struct.
** RETURN VALUES:
** Return 0 if success.
** -------------------------------------------------------------------------- */
int	pb(t_stack *stack)
{
	push(&stack->last_b, &stack->last_a);
	ft_putstr_fd("pb\n", 1);
	stack->size_a--;
	stack->size_b++;
	return (SUCCESS);
}
