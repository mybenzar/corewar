/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:20:09 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 16:01:00 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

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

uint8_t	is_zero_separator(t_corewar *corewar, t_champion *champion)
{
	char		buf[BUFFER_SIZE];
	uint32_t	*zero;

	if (read(champion->fd, buf, BUFFER_SIZE) == FAILURE)
	{
		corewar->error |= READ_ERR;
		return (FAILURE);
	}
	zero = (uint32_t *)buf;
	if (*zero == 0)
		return (TRUE);
	return (FALSE);
}

char	*get_champion_data(t_corewar *corewar, int fd, size_t size)
{
	char	*data;

	data = ft_memalloc(size + 1);
	if (data == NULL)
	{
		corewar->error |= MALLOC_ERR;
		return (NULL);
	}
	if (read(fd, data, size) == FAILURE)
		corewar->error |= READ_ERR;
	return (data);
}

uint32_t read_bytes_word(t_corewar *corewar, int fd)
{
	char		buf[BUFFER_SIZE];
	uint32_t	*word;

	if (read(fd, buf, BUFFER_SIZE) == FAILURE)
	{
		corewar->error |= READ_ERR;
		return (0);
	}
	rev_bytes(buf, BUFFER_SIZE);
	word = (uint32_t *)buf;
	return (*word);
}

int8_t	parser_champion(t_corewar *corewar, t_champion *champion)
{
	uint32_t	magic;

	(void)corewar;
	magic = read_bytes_word(corewar, champion->fd); // MAGIC
	// CHECK ERROR
	if (magic != COREWAR_EXEC_MAGIC)
	{
		// ERROR NOT BINARY
		return (FAILURE);
	}
	champion->name = get_champion_data(corewar, champion->fd, PROG_NAME_LENGTH); // NAME
	if (champion->name == NULL)
		return (FAILURE);
	if (is_zero_separator(corewar, champion) == FALSE) // ZERO SEP
		return (FAILURE);
	champion->prog_size = read_bytes_word(corewar, champion->fd); // PROG_SIZE
	// CHECK ERROR
	champion->comment = get_champion_data(corewar, champion->fd, COMMENT_LENGTH);
	if (champion->comment == NULL)
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
