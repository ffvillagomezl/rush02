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

/*
 * Recorre la cadena de entrada comprobando si está formada exclusivamente
 * por el carácter '0'.
 * Si llega al final ('\0') y ha contado al menos un cero, imprime la 
 * traducción correspondiente de "0", libera la memoria del búfer del 
 * diccionario, y devuelve 1 para indicar al main que debe terminar.
 */
int	ft_zero_check(char *num, char *buf)
{
	int	i;

	i = 0;
	// Avanza mientras el carácter sea '0'
	while (num[i] == '0')
		i++;
		
	// Si llegó al final de la cadena y procesó al menos un cero (evita strings vacíos)
	if (num[i] == '\0' && i > 0)
	{
		ft_write_num(buf, "0"); // Busca e imprime la traducción de "0"
		write(1, "\n", 1);
		free(buf);              // Libera el diccionario tempranamente
		return (1);             // Retorna verdadero (es un cero absoluto)
	}
	return (0); // No es solo ceros, el programa principal debe continuar
}