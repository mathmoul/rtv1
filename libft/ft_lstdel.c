/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 18:32:37 by mmoullec          #+#    #+#             */
/*   Updated: 2016/11/21 12:35:33 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *l;
	t_list *nxt;

	l = *alst;
	if (l)
	{
		while (l)
		{
			nxt = l->next;
			(*del)((l)->content, (l)->content_size);
			free(l);
			l = nxt;
		}
		*alst = NULL;
	}
}
