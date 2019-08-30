/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:05:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/30 16:17:15 by mybenzar         ###   ########.fr       */
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
# define READ_ERR				0x2000000000000000

# define BUFFER_SIZE			4

enum	e_operation
{
	NONE,
	LIVE,
	LD,
	ST,
	ADD,
	SUB,
	AND,
	OR,
	XOR,
	ZJMP,
	LDI,
	STI,
	FORK,
	LLD,
	LLDI,
	LFORK,
	AFF
};

typedef struct	s_champion
{
	char		*bin_name;
	char		*name;
	char		*comment;
	size_t		real_id;
	size_t		id;
	uint8_t		*pc;
	int			fd;
	uint32_t	prog_size;
	uint32_t	cycle;
	uint8_t		pc_offset;
}				t_champion;

typedef struct	s_arg
{
	uint8_t		*ptr;
	uint8_t		size;
}				t_arg;

typedef	struct  s_register
{
	uint8_t		byte[REG_SIZE];
}				t_register;

typedef struct	s_corewar
{
	t_list		*list_champion;
	uint64_t	nb_champion;
	uint64_t	error;
	uint32_t	total_cycles;
	t_arg		cur_arg[3];
	uint8_t		map[MEM_SIZE];
	t_register	reg[REG_NUMBER];
	uint8_t		carry;
}				t_corewar;


int8_t	init_champion(t_corewar *corewar, int ac, char **av);
void	load_champion(t_corewar *corewar);
void	print_champion(t_list *list_champion);
int8_t	game_loop(t_corewar *corewar);

/*
**** OPERATION FUNCTIONS
*/

void	write_to_memory(t_corewar *corewar, long long res, int arg_id);
int8_t	op_live(t_corewar *corewar, t_champion *champion);
int8_t	op_add(t_corewar *corewar, t_champion *champion);
int8_t	op_sub(t_corewar *corewar, t_champion *champion);
int8_t	op_ld(t_corewar *corewar, t_champion *champion);
int8_t	op_ldi(t_corewar *corewar, t_champion *champion);
int8_t	op_st(t_corewar *corewar, t_champion *champion);
int8_t	op_sti(t_corewar *corewar, t_champion *champion);
int8_t	op_and(t_corewar *corewar, t_champion *champion);
int8_t	op_or(t_corewar *corewar, t_champion *champion);
int8_t	op_xor(t_corewar *corewar, t_champion *champion);
int8_t	op_zjmp(t_corewar *corewar, t_champion *champion);
int8_t	op_aff(t_corewar *corewar, t_champion *champion);

#endif
