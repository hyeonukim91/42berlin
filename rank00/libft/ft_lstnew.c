/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 17:30:51 by hyeonuki          #+#    #+#             */
/*   Updated: 2024/12/14 21:12:31 by hyeonuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*output;

	output = (t_list *)malloc(sizeof(t_list));
	if (output == NULL)
		return (NULL);
	output->content = content;
	output->next = NULL;
	
	return(output);
}
