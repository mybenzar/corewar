/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:17:24 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 21:12:34 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar"

/*
**	--> op_st : store direct - directly transfers register value (stocked in
**	first argument) in the second argument. If the first argument equals 0,
**	carry is set to 1.
*/

int8_t		op_st(t_corewar *cor)
{
	long long	arg1;
	long long	arg2;

	arg1 = ef(corewar->arg[0].ptr, corewar->arg[0].size);
	arg2 = corewar->reg[arg1 - 1];
	write_to_memory(corewar, arg2, 1);
	if (arg1 == 0)
		corewar->carry = 1;
	return (SUCCESS);
}
