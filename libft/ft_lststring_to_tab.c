/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststring_to_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:59:59 by dmontgen          #+#    #+#             */
/*   Updated: 2020/10/12 15:22:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_lststring_to_tab(t_list *lst)
{
	char	**str;
	t_list	*iterator;
	int		i;

	i = 0;
	iterator = lst;
	if (!(str = malloc(sizeof(*str) * (ft_lstlen(lst) + 1))))
		return (NULL);
	while (iterator)
	{
		if (!(str[i] = ft_strdup(iterator->content)))
			return (NULL);
		iterator = iterator->next;
		i++;
	}
	str[i] = NULL;
	return (str);
}
