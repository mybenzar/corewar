/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:08:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/31 14:46:13 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

//get_addr(cur_ptr, arg_value, INIT_ORIGIN | IDX_OFF)

uint8_t		*get_addr(uint8_t *ptr, uint64_t offset, uint8_t opt)
{
	static uint8_t	*origin = NULL;

	if (opt & INIT_ORIGIN)
	{
		origin = ptr;
		return (NULL);
	}
	if (opt & IDX_ON)
		return ((ptr + (offset % IDX_MOD) - origin) % MEM_SIZE);
	return ((ptr + offset - origin) % MEM_SIZE);
}

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
	get_addr(NULL, 0, corewar.map);
	game_loop(&corewar);
	return (EXIT_SUCCESS);
}
