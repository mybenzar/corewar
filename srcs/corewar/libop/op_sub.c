/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:28:09 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 20:53:42 by mybenzar         ###   ########.fr       */
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
	int			i;

	(void)champion;
	i = 0;
	arg1 = ef(corewar->arg[0].ptr, corewar->arg[0].size);
	arg2 = ef(corewar->arg[1].ptr, corewar->arg[1].size);
	arg3 = arg1 - arg2;
	write_to_memory(corewar, arg3, 2);
	if (arg3 == 0)
		corewar->carry = 1;
	return (SUCCESS);
}
