/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:08:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 17:11:07 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_champion(t_list *list_champion)
{
	t_champion	*champion;

	while (list_champion != NULL)
	{
		champion = (t_champion *)list_champion->content;
		ft_printf("#######\nb_name:\t %s\nid:\t %zu\nreal_id: %zu\nfd:\t %d\n",
					champion->bin_name, champion->id, champion->real_id, champion->fd);
		ft_printf("p_size:\t %d\nname:\t %s\ncomment: %s\n#######\n",
					champion->prog_size, champion->name, champion->comment);
		list_champion = list_champion->next;
	}
}

void	error(uint64_t err)
{
	ft_dprintf(2, "ERROR: ");
	if (err & FD_ERR)
		ft_dprintf(2, "bad fd\n");
	else if (err & BAD_ARG_ERR)
		ft_dprintf(2, "bad arg\n");
	else if (err & TOO_MANY_CHAMPS_ERR)
		ft_dprintf(2, "Too many champions\n");
	else if (err & MALLOC_ERR)
		ft_dprintf(2, "malloc\n");
}

#include "math.h"

void	print_map(t_corewar *corewar)
{
	size_t	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x%c", corewar->map[i],
				(i + 1 == MEM_SIZE || (i + 1) % (size_t)(sqrt(MEM_SIZE)) == 0) ? '\n' : ' ');
		i++;
	}
}

int		main(int ac, char **av)
{
	t_corewar	corewar;

	ft_bzero(&corewar, sizeof(corewar));
	if (init_champion(&corewar, ac, av) == FAILURE)
	{
		error(corewar.error);
		///////// EXIT ROUTINE
		///////// CLOSE CHAMPION FD
		return (EXIT_FAILURE);
	}
	load_champion(&corewar);
	print_champion(corewar.list_champion); // DEBUG
	print_map(&corewar);

	ft_printf("\n\n --------------TESTS--------------\n");
	ft_printf("before, 3rd argument = %d\n", *(corewar.cur_arg[2].ptr));
	op_add(&corewar);
	ft_printf("after, 3rd argument = %d\n", *(corewar.cur_arg[2].ptr));
	return (EXIT_SUCCESS);
}
