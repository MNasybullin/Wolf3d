/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 09:09:41 by aannara           #+#    #+#             */
/*   Updated: 2020/02/21 21:38:30 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "head.h"

void	set_m(t_sdl *m)
{
	m->g_m.p = NULL;
	m->g_m.next = NULL;
	m->g_m.last = NULL;
}

void	new_m(void *pointer, t_sdl *m)
{
	t_mem	*new;
	t_mem	*tmp;

	new = (t_mem*)malloc(sizeof(t_mem));
	if (new == NULL)
		exit(0);
	new->p = pointer;
	new->next = NULL;
	new->last = new;
	if (m->g_m.last == NULL)
		m->g_m.next = new;
	else
	{
		tmp = (t_mem*)m->g_m.last;
		tmp->next = new;
	}
	m->g_m.last = new;
}

void	del_m(t_sdl *m)
{
	t_mem	*tmp;
	t_mem	*curr;

	curr = (t_mem*)m->g_m.next;
	while (curr != NULL)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

void	del_memory(t_sdl *m)
{
	t_mem	*tmp;

	tmp = m->g_m.next;
	while (tmp != NULL)
	{
		free(tmp->p);
		tmp = tmp->next;
	}
	del_m(m);
}

void	*mem(size_t size)
{
	void	*p;
	t_sdl	*m;

	m = get_sdl(0);
	p = malloc(size);
	new_m(p, m);
	return (p);
}
