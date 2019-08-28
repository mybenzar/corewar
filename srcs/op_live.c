/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:44:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/28 19:26:30 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

/*
**	--> op_live : launches live operation (0x01) that holds on 4 bytes
**	that represent the player's id
*/

int8_t		op_live(t_corewar *cor, t_champion *champ, t_arg *arg)
{
	int64_t		id;
	int64_t		tmp;
	int			i;

	i = 0;
	id = 1;
	tmp = arg.arg1;
	while (i < 4)
	{
		tmp >>=1;
		i++;
	}
	while (i != 0)
	{
		i--;
		if (tmp & 1)
			id = id + ft_power(2, i);
		tmp <<= 1;
	}
	if ((size_t)id != champ->real_id)
	{
		ft_printf("ERROR: Something is wrong with the player's ID\n");
		return (FAILURE);
	}
	ft_printf("Player %d is alive!\n", id);
	return (SUCCESS);
}
