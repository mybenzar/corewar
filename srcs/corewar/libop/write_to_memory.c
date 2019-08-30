/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 20:35:25 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 20:38:37 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	write_to_memory(t_corewar *corewar, long long res, int arg_id)
{
	int i;

	i = 0;
	while (i < corewar->cur_arg[arg_id].size)
	{
		corewar->cur_arg[arg_id].ptr[i] = (uint8_t)res;
		res >>= 8;
		i++;
	}
}
