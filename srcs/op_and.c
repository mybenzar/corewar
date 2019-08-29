/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:33:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 16:47:14 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	--> op_and : operates a logical and between the two first arguments and
**	stocks the result in the third argument. If the result is 0, carry is set
**	to 0.
*/

int8_t		op_and(t_corewar *cor)
{
	cor->cur_arg[2]->(*ptr) = cor->cur_arg[1]->(*ptr) && cor->cur_arg[0]->(*ptr);
	if (cor->cur_arg[2]->(*ptr) == 0)
		cor->carry = 1;
	return (SUCCESS);
}
