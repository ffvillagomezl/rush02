/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictonary_iterator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:57:27 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 22:57:40 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*ft_dictonary_iterator(char *dict)
{
	char	c;
	char	*buf;
	int		fd;
	int		buf_bytes;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	buf_bytes = 0;
	while (read(fd, &c, 1) > 0)
		buf_bytes++;
	close(fd);
	buf = (char *) malloc(buf_bytes);
	if (!buf)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	fd = open(dict, O_RDONLY);
	read(fd, buf, buf_bytes);
	close(fd);
	return (buf);
}
