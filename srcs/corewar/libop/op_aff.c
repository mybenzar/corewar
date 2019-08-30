/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 11:44:53 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/30 15:08:43 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

/*
**	--> op_aff : only has one argument which represents the register. Displays
**	the ascii character in base 10 corresponding to what the register contains.
*/

// modulo 256 applique ?
// faut-il convertir le code en decimal ?

int8_t		op_aff(t_corewar *corewar, t_champion *champion)
{
	long long	arg1;

	arg1 = ef(corewar->arg[0].ptr, corewar->arg[0].size);
	ft_printf("%c", corewar->reg[arg1 - 1] % 256);
	return (SUCCESS);
}
