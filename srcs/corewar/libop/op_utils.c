/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 15:15:18 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/31 15:15:45 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "corewar.h"

long long	read_arg(uint8_t *ptr, uint8_t size)
{
	uint8_t		i;
	long long	out;

	i = 0;
	out = 0;
	while (i < size)
	{
		out	|= (long long )(*ptr) << ft_pow(2, i * 8);
		i++;
	}
	return (out);
}

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
