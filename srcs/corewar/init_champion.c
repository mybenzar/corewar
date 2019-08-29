/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:45:12 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 16:01:54 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "corewar.h"

int			reverse_order(void *champ_a, void *champ_b)
{
	return (((t_champion *)champ_a)->real_id > ((t_champion *)champ_b)->real_id);
}

static t_list	*create_champion_node(t_corewar *corewar, char *name, int id)
{
	t_champion	champion;
	t_list		*node;
	int			fd;

	champion.bin_name = NULL;
	node = NULL;
	fd = open(name, O_RDONLY);
	if (fd == FAILURE)
		corewar->error |= FD_ERR;
	else
	{
		champion.fd = fd;
		champion.real_id = id;
		champion.bin_name = ft_strdup(name);
		if (champion.bin_name == NULL)
			corewar->error |= MALLOC_ERR;
		else
			node = ft_lstnew(&champion, sizeof(champion));
	}
	return (node);
}

static uint8_t	is_n_option(char *s)
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

static void		rewrite_champions_id(t_list *list_champion)
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

static int8_t		get_champion(t_corewar *corewar, int ac, char **av)
{
	t_list		*node;
	char		*ptr;
	size_t		id_association;
	int			i;

	i = 0;
	id_association = 1;
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

int8_t	init_champion(t_corewar *corewar, int ac, char **av)
{
	if (get_champion(corewar, ac - 1, av + 1) == FAILURE)
		return (FAILURE);
	rewrite_champions_id(corewar->list_champion);
	return (SUCCESS);
}
