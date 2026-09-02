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

/*
 * Lee el archivo del diccionario dos veces:
 * La primera vez cuenta cuántos bytes (caracteres) tiene para saber cuánto malloc hacer.
 * La segunda vez guarda todo el contenido en el buffer reservado.
 */
char	*ft_dictonary_iterator(char *dict)
{
	char	c;
	char	*buf;
	int		fd;
	int		buf_bytes;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	
	// Contar bytes para el malloc
	buf_bytes = 0;
	while (read(fd, &c, 1) > 0)
		buf_bytes++;
	close(fd);
	
	// Reservar memoria exacta
	buf = (char *) malloc(buf_bytes);
	if (!buf)
	{
		write(2, "Dict Error\n", 11);
		return (0);
	}
	
	// Segunda lectura para llenar el búfer
	fd = open(dict, O_RDONLY);
	read(fd, buf, buf_bytes);
	close(fd);
	return (buf);
}
