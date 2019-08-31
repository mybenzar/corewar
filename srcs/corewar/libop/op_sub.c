/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:28:09 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/31 15:31:16 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar"

/*
**	--> op_sub : arithmetical substraction, substracts the second argument to
**	the first and stocks it in the third argument. If the result is 0, carry
**	is set to 1.
*/

int8_t		op_sub(t_corewar *corewar, t_champion *champion)
{
	long long	arg1;
	long long	arg2;
	long long	arg3;

	(void)champion;
	arg1 = read_arg(corewar->cur_arg[0].ptr, corewar->cur_arg[0].size);
	arg2 = read_arg(corewar->cur_arg[1].ptr, corewar->cur_arg[1].size);
	if (arg1 - arg2 == 0)
		corewar->carry = 1;
	corewar->reg[arg3 - 1] = arg1 - arg2;
	return (SUCCESS);
}
