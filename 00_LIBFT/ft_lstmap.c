/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:40:39 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/22 01:21:32 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_lstmap(void *content)
{
	t_list	*new;

	new = malloc (sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new -> content = content;
	new -> next = NULL;
	return (new);
}

void	ft_lstclear_lstmap(t_list **lst, void (*del)(void *))
{
	t_list	*copy;
	t_list	*tmp;

	copy = *lst;
	while (copy)
	{
		tmp = copy -> next;
		del(copy -> content);
		free(copy);
		copy = tmp;
	}
	*lst = NULL;
}

void	ft_lstadd_back_lstmap(t_list **lst, t_list *new)
{
	t_list	*copy;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	while (copy -> next)
		copy = copy -> next;
	copy -> next = new;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	new = NULL;
	while (lst)
	{
		tmp = ft_lstnew_lstmap((*f)(lst -> content));
		if (tmp == NULL)
		{
			ft_lstclear_lstmap(&new, del);
			return (NULL);
		}
		ft_lstadd_back_lstmap(&new, tmp);
		lst = lst -> next;
	}
	return (new);
}
