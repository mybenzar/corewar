/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:58:58 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 21:12:10 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

/*
**	--> op_ldi : load indirect operation (0x02) - sums the two first arguments
**	and loads the value stored at the address of the resulting sum in the
**	register specified by the third argument. If the sum is 0, carry is set to 1.
*/

// verifier que le carry est bien mis a 1 dans ces conditions la
// verifier l'ambiguite du sujet par rapport a "valeur de la taille d'un registre"
// verifier que l'index de corewar->map est correct

int8_t	op_ldi(t_corewar *corewar, t_champion *champion)
{
	long long arg1;
	long long arg2;

	(void)champion;
	arg1 = ef(corewar->arg[0].ptr, corewar->arg[0].size);
	arg2 = ef(corewar->arg[1].ptr, corewar->arg[1].size);
	arg3 = ef(corewar->arg[2].ptr, corewar->arg[2].size);
	mem = arg1 + arg2;
	corewar->reg[arg3 - 1] = corewar->map[mem - 1];
	if (mem == 0)
		corewar->carry = 1;
	return (SUCCESS);
}
