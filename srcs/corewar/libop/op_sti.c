/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 21:07:35 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 21:12:09 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

/*
**	--> op_sti : store indirect - sums the last two arguments and loads the
**	value stored at the memory address corresponding to the resulting sum
**	in the register specified by the first argument. If the sum is equal to 0,
**	carry is set to 1.
*/

int8_t		op_sti(t_corewar *cor)
{
	long long	arg1;
	long long	arg2;

	(void)champion;
	arg1 = ef(corewar->arg[0].ptr, corewar->arg[0].size);
	arg2 = ef(corewar->arg[1].ptr, corewar->arg[1].size);
	arg3 = ef(corewar->arg[2].ptr, corewar->arg[2].size);
	mem = arg2 + arg3;
	corewar->reg[arg1 - 1] = corewar->map[mem - 1];
	if (mem == 0)
		corewar->carry = 1;
	return (SUCCESS);
}
