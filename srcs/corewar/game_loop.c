/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:41 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/30 15:20:22 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

#include "math.h"

void	print_map(t_corewar *corewar)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("\033[38;5;%dm%.2x\033[0m%c",
				corewar->map[i] == 0 ? 255
				: 256 - corewar->map[i], corewar->map[i],
				(i + 1 == MEM_SIZE || (i + 1) % (size_t)(sqrt(MEM_SIZE)) == 0)
				? '\n' : ' ');
		i++;
	}
}

enum e_operation get_mem_data(t_corewar *corewar, t_champion *champion)
{
	enum	e_operation op;
	t_arg	*arg;
	uint8_t	ocp;
	uint8_t	i;
	uint8_t	mask;

	arg = corewar->cur_arg;
	op = *(champion->pc);
	champion->pc_offset = 1;
	ocp = *(champion->pc + champion->pc_offset);
	i = 1;
	while (i <= 3)
	{
		ocp = ocp >> 2;
		mask = ocp & 0b00000011;
		if (mask == 0b00000000)
			arg[i].size = 0; 
		else if (mask == 0b00000001)
			arg[i].size = T_REG;
		else if (mask == 0b00000010)
			arg[i].size = T_DIR;
		else
			arg[i].size = T_IND;
		arg[i].ptr = champion->pc + champion->pc_offset;
		if (arg[i].size == 0)
			arg[i].ptr = NULL;
		champion->pc_offset += arg[i].size;
		i++;
	}
	return (op);
}

int8_t	game_loop(t_corewar *corewar)
{
	enum e_operation	op;
	t_champion			*champion;
	t_list				*list;

	op = NONE;
	while (corewar->total_cycles < CYCLE_TO_DIE) // LIVE
	{
		list = corewar->list_champion;
		while (list != NULL)
		{
			champion = (t_champion *)list->content;
			if (champion->cycle == 0)
			{
				//if (op != NONE)
				//	compute_op[op](corewar, champion);
				op = get_mem_data(corewar, champion);
				print_map(corewar);
				return (FAILURE);
			}
			else
				champion->cycle--;
			corewar->total_cycles++;
			list = list->next;
		}
		//print_map(corewar);
	}
	return (SUCCESS);
}
