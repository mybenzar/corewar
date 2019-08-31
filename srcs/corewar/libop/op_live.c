/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:44:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/31 15:15:36 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

/*
**	--> op_live : launches live operation (0x01) that holds on 4 bytes
**	that represent the player's id
*/

int8_t		op_live(t_corewar *corewar, t_champion *champion)
{
	long long arg1;

	(void)champion;
	arg1 = read_arg(corewar->cur_arg[0].ptr, corewar->cur_arg[0].size);
	ft_printf("Player %lld is alive!\n", arg1);
	return (SUCCESS);
}
