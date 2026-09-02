/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: favillag <favillag@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 22:24:21 by favillag          #+#    #+#             */
/*   Updated: 2026/08/30 22:24:23 by favillag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*
 * Comprueba si la cadena proporcionada está compuesta únicamente por 
 * dígitos del '0' al '9'. Si encuentra letras, signos (como el '-') 
 * u otros caracteres, devuelve 0 (falso).
 */
int	ft_is_numeric(char *str)
{
	int	i;

	i = 0;
	// Si la cadena está vacía, no es un número válido
	if (str[i] == '\0')
		return (0);
		
	// Recorre la cadena completa
	while (str[i])
	{
		// Si el carácter está fuera del rango ASCII de los números
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1); // Todo está correcto, es numérico
}
