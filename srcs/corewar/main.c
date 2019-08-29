/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:08:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 15:17:37 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	print_champion(t_list *list_champion)
{
	t_champion	*champion;

	while (list_champion != NULL)
	{
		champion = (t_champion *)list_champion->content;
		ft_printf("#######\nname:\t %s\nid:\t %zu\nreal_id: %zu\nfd:\t %d\n#######\n",
					champion->bin_name, champion->id, champion->real_id, champion->fd);
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
	return (EXIT_SUCCESS);
}
