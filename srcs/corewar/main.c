/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:08:38 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/27 14:47:53 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"
#include "op.h"
#include <fcntl.h>

int			reverse_order(void *champ_a, void *champ_b)
{
	return (((t_champion *)champ_a)->id > ((t_champion *)champ_b)->id);
}

t_list		*create_champion_node(t_corewar *corewar, char *name, int id)
{
	t_champion	champion;
	t_list		*node;
	int			fd;

	champion.name = NULL;
	node = NULL;
	fd = open(name, O_RDONLY);
	if (fd == FAILURE)
		corewar->error |= FD_ERR;
	else
	{
		champion.fd = fd;
		champion.id = id;
		champion.name = ft_strdup(name);
		if (champion.name == NULL)
			corewar->error |= MALLOC_ERR;
		else
			node = ft_lstnew(&champion, sizeof(champion));
	}
	return (node);
}

uint8_t		is_n_option(char *s)
{
	if (*s != '-')
		return (FALSE);
	s++;
	while (*s != '\0')
	{
		if (*s != 'n')
			return (FALSE);
		s++;
	}
	return (TRUE);
}

int8_t		get_champion(t_corewar *corewar, int ac, char **av)
{
	t_list		*node;
	char		*ptr;
	size_t		id_association;
	int			i;

	i = 0;
	id_association = 0;
	while (i < ac)
	{
		if (i + 1 != ac && is_n_option(av[i]), ft_str_is_numeric(av[i + 1]) == TRUE)
			id_association = atol(av[++i]);
		else if ((ptr = ft_strstr(av[i], ".cor")) != NULL && ptr[4] == '\0')
		{
			node = create_champion_node(corewar, av[i], id_association);
			if (node == NULL)
				corewar->error |= MALLOC_ERR;
			ft_lstadd_back(&corewar->list_champion, node);
			corewar->nb_champion++;
			if (corewar->nb_champion > MAX_PLAYERS)
				corewar->error |= TOO_MANY_CHAMPS_ERR;
			id_association++;
		}
		else
			corewar->error |= BAD_ARG_ERR;
		i++;
	}
	ft_lst_mergesort(&corewar->list_champion, reverse_order);
	return (corewar->error ? FAILURE : SUCCESS);
}

void	print_champion(t_list *list_champion)
{
	t_champion	*champion;

	while (list_champion != NULL)
	{
		champion = (t_champion *)list_champion->content;
		ft_printf("#######\nname:\t%s\nid:\t%zu\nfd:\t%d\n#######\n",
					champion->name, champion->id, champion->fd);
		list_champion = list_champion->next;
	}
}

void	rewrite_champions_id(t_list *list_champion)
{
	t_champion	*champion;
	size_t			id;

	id = 1;
	while (list_champion != NULL)
	{
		champion = (t_champion *)list_champion->content;
		champion->id = id;
		list_champion = list_champion->next;
		id++;
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
	if (get_champion(&corewar, ac - 1, av + 1) == FAILURE)
	{
		error(corewar.error);
		///////// EXIT ROUTINE
		return (EXIT_FAILURE);
	}
	print_champion(corewar.list_champion); // DEBUG
	rewrite_champions_id(corewar.list_champion); // DEBUG
	print_champion(corewar.list_champion); // DEBUG
	return (EXIT_SUCCESS);
}
