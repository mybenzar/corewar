/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_xor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:48:35 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 20:53:52 by mybenzar         ###   ########.fr       */
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
	arg1 = ef(corewar->cur_arg[0].ptr, corewar->cur_arg[0].size);
	arg2 = ef(corewar->cur_arg[1].ptr, corewar->cur_arg[1].size);
	arg3 = arg1 ^ arg2;
	write_to_memory(corewar, arg3, 2);
	if (arg3 == 0)
		corewar->carry = 1;
	return (SUCCESS);
}
