/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:05:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/29 16:47:15 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"
# include "op.h"

/*
**** ERROR
*/

# define NO_ERR					0x0000000000000000
# define FD_ERR					0x0000000000000001
# define BAD_ARG_ERR			0x0000000000000002
# define TOO_MANY_CHAMPS_ERR	0x0000000000000004

# define MALLOC_ERR				0x1000000000000000

# define BUFFER_SIZE			4

typedef struct	s_champion
{
	char		*bin_name;
	char		*name;
	uint8_t		*pc;
	size_t		real_id;
	size_t		id;
	int			fd;
}				t_champion;

typedef struct	s_arg
{
	uint8_t		*ptr;
	enum e_type	type;
	uint8_t		size;
}				t_arg;

typedef struct	s_corewar
{
	t_list		*list_champion;
	uint64_t	nb_champion;
	uint64_t	error;
	t_register	reg[REG_NUMBER];
	uint8_t		carry;
	uint8_t		map[MEM_SIZE];
	t_arg		cur_arg[3];
}				t_corewar;

typedef	struct  s_register
{
	uint8_t		byte[REG_SIZE];
}				t_register;

int8_t	init_champion(t_corewar *corewar, int ac, char **av);
void	load_champion(t_corewar *corewar);
void	print_champion(t_list *list_champion);

#endif
