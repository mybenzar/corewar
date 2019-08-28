/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 17:44:28 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/28 18:11:07 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "ft_printf.h"

/*
**	--> op_live : launches live operation (0x01) that holds on 4 bytes
**	that represent the player's id
*/

// unused variable cor

int		op_live(t_corewar *cor, t_arg *arg)
{
	int		id;
	t_list	*tmp;

	tmp = corewar->list_champion;
	while (tmp != NULL)
	{
		if ()
		tmp = tmp->next;
	}
	id = ft_atoi_base(arg.arg1);
	ft_printf("Player %d is alive!\n", id);
	return (SUCCESS);
}
