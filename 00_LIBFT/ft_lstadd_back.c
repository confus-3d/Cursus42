/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-los- <fde-los-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 23:47:43 by fde-los-          #+#    #+#             */
/*   Updated: 2023/08/22 00:01:46 by fde-los-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
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
