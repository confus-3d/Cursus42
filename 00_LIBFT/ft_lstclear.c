/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:17:28 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/22 01:13:29 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
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
