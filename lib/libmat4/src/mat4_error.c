/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wwatkins <wwatkins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 18:20:21 by wwatkins          #+#    #+#             */
/*   Updated: 2016/12/03 11:59:54 by wwatkins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

void	matrix_error(int exit_program, int error)
{
	if (error == MATRIX_ADDITION_ERR)
		printf("ERROR: matrix ADDITION, invalid dimensions.\n");
	else if (error == MATRIX_SUBSTRACTION_ERR)
		printf("ERROR: matrix SUBSTRACTION, invalid dimensions.\n");
	else if (error == MATRIX_MULTIPLICATION_ERR)
		printf("ERROR: matrix MULTIPLICATION, invalid dimensions.\n");
	else if (error == MATRIX_TRANSPOSE_ERR)
		printf("ERROR: matrix TRANSPOSE, invalid dimensions.\n");
	else if (error == MATRIX_COPY_DATA_ERR)
		printf("ERROR: matrix COPY_DATA, invalid dimensions.\n");
	if (exit_program)
		exit(0);
}
