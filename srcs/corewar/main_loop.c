/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 17:11:41 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 17:44:02 by ffoissey         ###   ########.fr       */
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

enum e_poeration get_mem_data(t_champion *champion, t_arg *arg)
{
	(void)arg;
	(void)champion;
	return (NONE);
}

int8_t	game_loop(t_corewar *corewar)
{
	enum e_operation	op;
	t_champion			*champion;
	t_list				*list;
	t_args				cur_arg;
	

	op = NONE;
	while (1) // LIVE
	{
		list = corewar->ist_champion;
		while (list != NULL)
		{
			champion = (champion *)list->content;
			if (champion->tic == 0)
			{
				op = get_mem_data(champion, &cur_arg);
				compute_op[op](&cur_arg);
			}
			else
				champion->tic--;
			list = list->next;
		}
		print_map(corewar);
	}
	return (SUCCESS);
}
