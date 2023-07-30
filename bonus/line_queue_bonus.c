/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_queue_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aajaanan <aajaanan@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:02:25 by aajaanan          #+#    #+#             */
/*   Updated: 2023/07/30 14:36:40 by aajaanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_line_queue(t_line_queue *q)
{
	q->front = NULL;
	q->rear = NULL;
}

void	enqueue_line(t_line_queue *q, char *line)
{
	struct s_line_queue_node	*new_node;

	new_node = (struct s_line_queue_node *)malloc
		(sizeof(struct s_line_queue_node));
	new_node->val = line;
	new_node->next = NULL;
	if (q->front == NULL)
	{
		q->front = new_node;
		q->rear = new_node;
	}
	else
	{
		q->rear->next = new_node;
		q->rear = new_node;
	}
}

char	*dequeue_line(t_line_queue *q)
{
	struct s_line_queue_node	*tmp;
	char						*line;

	tmp = q->front;
	q->front = q->front->next;
	line = tmp->val;
	free(tmp);
	return (line);
}

int	line_queue_is_empty(t_line_queue *q)
{
	if (q->front == NULL)
		return (1);
	return (0);
}

int	line_queue_size(t_line_queue *q)
{
	struct s_line_queue_node	*tmp;
	int							size;

	size = 0;
	tmp = q->front;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
