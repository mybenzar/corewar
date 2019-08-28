/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:05:04 by ffoissey          #+#    #+#             */
/*   Updated: 2019/08/28 17:36:09 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include "libft.h"

/*
**** ERROR
*/

# define NO_ERR					0x0000000000000000
# define FD_ERR					0x0000000000000001
# define BAD_ARG_ERR			0x0000000000000002
# define TOO_MANY_CHAMPS_ERR	0x0000000000000004

# define MALLOC_ERR				0x1000000000000000

typedef struct	s_champion
{
	char		*name;
	size_t		id;
	int			fd;
}				t_champion;

typedef struct	s_arg
{
	int			arg1;
	int			arg2;
	int			arg3;
}				t_arg;

typedef struct	s_corewar
{
	t_list		*list_champion;
	uint64_t	nb_champion;
	uint64_t	error;
}				t_corewar;

#endif
