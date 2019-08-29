/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:51:32 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 20:58:39 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	--> op_zjmp : if carry equals 1, jumps to the memory address specified in
**	the first argument.
*/

// il faut passer pc dans une structure pour pouvoir le modifier ici et faire le jump

int8_t	op_zjmp(t_corewar *corewar, t_champion *champion)
{
	long long arg1;

	(void)champion;
	arg1 = ef(corewar->arg[0].ptr, corewar->arg[0].size);
	if (corewar->carry == 1)
// WIP
	return (SUCCESS);
}
