/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:37:59 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 15:27:42 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

/*
**	--> op_ld : load direct operation (0x02) - loads the first argument in the
**	register (represented in the second argument). If the first argument is 0,
**	carry takes the value of 1.
*/

// verifier que l'index de reg est le bon, les index envoyes commencent a 1
// mais reg commence a 0
// reg est en big endian

int8_t		op_ld(t_corewar *cor)
{
	cor->reg[cor->cur_arg[1]->val - 1] = cor->cur_arg[0];
	if (cor->cur_arg[0] == 0)
		cor->carry = 1;
	return (SUCCESS);
}
