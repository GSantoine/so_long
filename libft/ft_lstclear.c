/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:38:47 by agras             #+#    #+#             */
/*   Updated: 2021/12/12 21:39:16 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*delete_elem(t_list *lst, void (*del)(void*))
{
	t_list	*tmp;

	tmp = lst->next;
	ft_lstdelone(lst, del);
	return (tmp);
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!*lst)
		return ;
	while (*lst)
		*lst = delete_elem(*lst, del);
}
