/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:44:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 14:25:16 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

/*
**	--> op_live : launches live operation (0x01) that holds on 4 bytes
**	that represent the player's id
*/

int8_t		op_live(t_corewar *cor)
{
	ft_printf("Player %d is alive!\n", cor->cur_arg[0]->val);
	return (SUCCESS);
}
