/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:44:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/28 17:36:08 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

/*
**	--> op_live : launches live operation (0x01) that holds on 4 bytes
**	that represent the player's id
*/

int		op_live(t_corewar *cor, t_arg *arg)
{
	int	id;

	id = ft_atoi_base(arg.arg1);
	ft_printf("Player %d is alive!\n", id);
}
