/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-ham <aben-ham@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:19:19 by aben-ham          #+#    #+#             */
/*   Updated: 2022/02/15 16:20:18 by aben-ham         ###   ########.fr       */
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
	
	printf("\n");
	system("leaks stack");
	return (0);
}
