/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:41:17 by favillag          #+#    #+#             */
/*   Updated: 2026/08/29 20:43:57 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/* Verifica si a partir del índice 'i' en el diccionario, 
 * los siguientes caracteres coinciden exactamente con la key 'digits'.
 * Retorna la posición de los ':' si es una coincidencia, de lo contrario -1.
 */
int	match_line(char *buf, int i, char *digits, int digit_len)
{
	int	j = 0;

	while (j < digit_len && buf[i + j] == digits[j])
		j++;
		
	if (j == digit_len) // Si coincidió el string numérico entero
	{
		i += j;
		while (buf[i] == ' ') // Consume espacios post-número
			i++;
		if (buf[i] == ':')    // Si sigue el separador, es un match válido
			return (i);
	}
	return (-1);
}

/* Imprime todos los caracteres de la línea después de los ':' 
 * hasta encontrarse con el salto de línea.
 */
void	print_word(char *buf, int i)
{
	if (buf[i] == ':')
		i++;
	while (buf[i] == ' ') // Elimina los espacios iniciales del valor
		i++;
	while (buf[i] && buf[i] != '\n')
	{
		write(1, &buf[i], 1);
		i++;
	}
	write(1, " ", 1); // Deja un espacio para la siguiente palabra
}

/* Escanea el buffer línea por línea buscando la coincidencia. 
 * Se asegura de que la coincidencia esté al principio de una línea.
 */
void	ft_write_num(char *buf, char *digits)
{
	int	i = 0;
	int	digit_len = ft_strlen(digits);
	int	colon_pos;

	while (buf[i])
	{
		// Solo evalúa si estamos al inicio del búfer o justo después de un salto de línea
		if (i == 0 || buf[i - 1] == '\n')
		{
			colon_pos = match_line(buf, i, digits, digit_len);
			if (colon_pos != -1)
			{
				print_word(buf, colon_pos);
				return ; // Termina tan pronto encuentra e imprime la palabra
			}
		}
		i++;
	}
}