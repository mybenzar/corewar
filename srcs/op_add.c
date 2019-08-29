/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:22:59 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 15:27:03 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	--> op_add : arithmetical addition of the first two arguments, stocks the
**	result in the third argument and if it is equal to 0, sets carry to 1.
*/

//reverse result of addition in order to have it in big endian

int8_t	op_add(t_corewar *cor)
{
	cor->cur_arg[2]->(*ptr) = cor->cur_arg[0]->val + cor->cur_arg[1]->val;
	if (cor->cur_arg[2] == 0)
		cor->carry = 1;
	return (SUCCESS);
}
