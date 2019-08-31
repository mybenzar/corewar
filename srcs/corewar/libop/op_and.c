/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:33:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/31 15:51:48 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	--> op_and : operates a bitwise AND between the two first arguments and
**	stocks the result in the third argument. If the result is 0, carry is set
**	to 0.
*/

int8_t		op_and(t_corewar *corewar, t_champion *champion)
{
	long long	arg1;
	long long	arg2;

	(void)champion;
	arg1 = read_arg(corewar->cur_arg[0].ptr, corewar->cur_arg[0].size);
	if (corewar->cur_arg[0].size & T_REG)
		arg1 = corewar->reg[arg1 - 1];
	if (corewar->cur_arg[0].size & T_IND)
		arg1 = corewar->reg[arg1 - 1];
	arg2 = read_arg(corewar->cur_arg[1].ptr, corewar->cur_arg[1].size);
	arg3 = arg1 & arg2;
	write_to_memory(corewar, arg3, 2);
	if (arg3 == 0)
		corewar->carry = 1;
	return (SUCCESS);
}
