/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:22:59 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 20:52:57 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	--> op_add : arithmetical addition of the first two arguments, stocks the
**	result in the third argument and if it is equal to 0, sets carry to 1.
*/

int8_t	op_add(t_corewar *corewar, t_champion *champion)
{
	long long	arg1;
	long long	arg2;
	long long	arg3;

	(void)champion;
	arg1 = ef(corewar->cur_arg[0].ptr, corewar->cur_arg[0].size);
	arg2 = ef(corewar->cur_arg[1].ptr, corewar->cur_arg[1].size);
	arg3 = arg1 + arg2;
	write_to_memory(corewar, arg3, 2);
	if (arg3 == 0)
		corewar->carry = 1;
	return (SUCCESS);

