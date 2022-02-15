/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:19:19 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 16:56:15 by aben-ham         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"
#include <stdio.h>

void	*p_int(int a)
{
	int	*p;

	p = malloc(4);
	*p = a;
	return (p);
}

void	*c_int(void *p)
{
	int	*n;

	n = malloc(4);
	*n = *((int *)p);
	return (n);
}

int	main(void)
{
	t_queue	*queue;
	t_queue	*c_queue;
	void	*p;

	queue = q_init();
	q_enqueue(queue, p_int(10));
	q_enqueue(queue, p_int(15));
	q_enqueue(queue, p_int(13));
	//q_clear(queue, NULL);
	c_queue = q_clone(queue, c_int);
	p = q_dequeue(c_queue);
	while (p)
	{
		printf("%d ->, ", *(int *)p);
		free(p);
		p = q_dequeue(c_queue);
	}
	printf("\n");
	system("leaks queue");
	return (0);
}
