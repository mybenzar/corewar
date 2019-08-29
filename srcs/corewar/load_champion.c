/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:20:09 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 15:20:32 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

uint8_t	is_bin_file(uint32_t *header)
{
	return (*header == COREWAR_EXEC_MAGIC);
}

void	rev_bytes(char *byte, uint8_t size)
{
	uint8_t	i;
	char	swap;

	i = 0;
	while (i < size)
	{
		swap = byte[i];
		byte[i] = byte[size - 1];
		byte[size - 1] = swap;
		i++;
		size--;
	}
}

uint8_t	is_zero_separator(t_champion *champion)
{
	char		buf[BUFFER_SIZE];
	uint32_t	*zero;

	if (read(champion->fd, buf, BUFFER_SIZE) == FAILURE)
	{
		//READ_ERROR
		return (FAILURE);
	}
	zero = (uint32_t *)buf;
	if (*zero == 0)
		return (TRUE);
	return (FALSE);
}

int8_t	get_champion_name(t_champion *champion)
{
	char	buf[PROG_NAME_LENGTH];

	if (read(champion->fd, buf, PROG_NAME_LENGTH) == FAILURE)
	{
		//READ_ERROR
		return (FAILURE);
	}
	champion->name = ft_memalloc(PROG_NAME_LENGTH + 1);
	if (champion->name == NULL)
	{
		//MALLOC_ERROR
		return (FAILURE);
	}
	ft_strcpy(champion->name, buf);
	return (SUCCESS);
}

int8_t	parser_champion(t_corewar *corewar, t_champion *champion)
{
	char	buf[BUFFER_SIZE];

	(void)corewar;
	if (read(champion->fd, buf, BUFFER_SIZE) == FAILURE)
	{
		//READ_ERROR
		return (FAILURE);
	}
	rev_bytes(buf, BUFFER_SIZE);
	if (is_bin_file((uint32_t *)buf) == FALSE)
	{
		// ERROR NOT BINARY
		return (FAILURE);
	}
	if (get_champion_name(champion) == FAILURE)
		return (FAILURE);
	ft_printf("champion name: %s\n", champion->name);
	if (is_zero_separator(champion) == FALSE)
		return (FAILURE);
	return (SUCCESS);
}

void	load_champion(t_corewar *corewar)
{
	t_champion	*champion;
	size_t			scale;
	t_list			*list_champion;

	scale = 0;
	list_champion = corewar->list_champion;
	while (list_champion != NULL)
	{
		champion = (t_champion *)list_champion->content;
		champion->pc =  corewar->map + scale;
		parser_champion(corewar, champion);
		scale = (scale + MEM_SIZE / corewar->nb_champion) % MEM_SIZE; 
		list_champion = list_champion->next;
	}
}
