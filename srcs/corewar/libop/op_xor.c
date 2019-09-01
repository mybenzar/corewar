/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:48:35 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/31 15:24:41 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	--> op_xor : operates a bitwise XOR between the two first arguments and
**	stocks the result in the third argument. If the result is 0, carry is set
**	to 0.
*/

int8_t	op_xor(t_corewar *corewar, t_champion *champion)
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
	if (corewar->cur_arg[1].size & T_REG)
		arg2 = corewar->reg[arg2 - 1];
	if (corewar->cur_arg[1].size & T_IND)
		arg2 = corewar->reg[arg2 - 1];
	arg3 = read_arg(corewar->cur_arg[2].ptr, corewar->cur_arg[2].size);
	if (arg1 ^ arg2 == 0)
		corewar->carry = 1;
	corewar->reg[arg3 - 1] = arg1 ^ arg2;
	return (SUCCESS);
}
