/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:17:24 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/30 11:46:16 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar"

/*
**	--> op_st : store direct - directly transfers register value (stocked in
**	first argument) in the second argument. If the first argument equals 0,
**	carry is set to 1.
*/

// modifier si jamais index ou registre

int8_t		op_st(t_corewar *corewar, t_champion *champion)
{
	long long	arg1;
	long long	arg2;

	(void)champion;
	arg1 = ef(corewar->cur_arg[0].ptr, corewar->cur_arg[0].size);
	arg2 = corewar->reg[arg1 - 1];
	write_to_memory(corewar, arg2, 1);
	if (arg1 == 0)
		corewar->carry = 1;
	return (SUCCESS);
}
