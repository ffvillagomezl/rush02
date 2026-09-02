/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:39:20 by favillag          #+#    #+#             */
/*   Updated: 2026/08/29 20:40:23 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	ft_parse_args(int argc, char *argv[], char **dict, char **num);

int	main(int argc, char *argv[])
{
	char	*num;
	char	*dict;
	char	*buf;

	num = NULL;
	dict = "numbers.dict"; // Diccionario por defecto
	
	// 1. Parseo de argumentos y validación de errores
	if (!ft_parse_args(argc, argv, &dict, &num))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	
	// 2. Carga del diccionario en memoria (búfer)
	buf = ft_dictonary_iterator(dict);
	if (!buf)
		return (0);
		
	// 3. Caso especial: si el número es "0" o "000", se imprime y termina
	if (ft_zero_check(num, buf))
		return (0);
		
	// 4. Algoritmo principal: trocea el número y lo traduce
	ft_divide_in_groups(buf, num, dict);
	write(1, "\n", 1);
	
	// 5. Liberación de memoria del diccionario
	free(buf);
	return (0);
}

/* 
 * Asigna los punteros dict y num dependiendo de la cantidad de argumentos.
 * Retorna 0 (falso) si la cantidad de argumentos es inválida o si
 * el número contiene caracteres que no son dígitos.
 */
int	ft_parse_args(int argc, char *argv[], char **dict, char **num)
{
	if (argc == 2)
		*num = argv[1];
	else if (argc == 3)
	{
		*dict = argv[1];
		*num = argv[2];
	}
	else
		return (0);
		
	if (!ft_is_numeric(*num))
		return (0);
	return (1);
}