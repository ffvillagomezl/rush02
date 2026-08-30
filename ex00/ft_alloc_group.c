/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc_group.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:50:40 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 21:50:44 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*ft_alloc_group(char *num, int num_len, int i, int *curr)
{
	char	*group;
	int		len;
	int		j;

	if (i == 0)
		len = get_group_len(num_len);
	else
		len = 3;
	group = malloc(len + 1);
	if (!group)
		return (NULL);
	j = 0;
	while (j < len)
	{
		group[j] = num[*curr + j];
		j++;
	}
	group[j] = '\0';
	*curr += len;
	return (group);
}
