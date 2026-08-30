/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 21:40:37 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 21:40:39 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_zero_check(char *num, char *buf)
{
	int	i;

	i = 0;
	while (num[i] == '0')
		i++;
	if (num[i] == '\0' && i > 0)
	{
		ft_write_num(buf, "0");
		write(1, "\n", 1);
		free(buf);
		return (1);
	}
	return (0);
}
