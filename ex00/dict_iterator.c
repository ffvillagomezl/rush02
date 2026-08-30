/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_iterator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:32:46 by favillag          #+#    #+#             */
/*   Updated: 2026/08/29 20:40:29 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

char	*dict_iterator(char *dict)
{
	char	c;
	char	*buf;
	int		fd;
	int		buf_bytes;

	fd = open(dict, O_RDONLY);
	if (!fd)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	buf_bytes = 0;
	while (read(fd, &c, 1) > 0)
		buf_bytes++;
	buf = (char *) malloc(buf_bytes);
	close(fd);
	if (!buf)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	fd = open(dict, O_RDONLY);
	read(fd, buf, buf_bytes);
	//write(1, buf, buf_bytes);
	return (buf);
}
