/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 11:22:59 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 16:15:47 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	--> op_add : arithmetical addition of the first two arguments, stocks the
**	result in the third argument and if it is equal to 0, sets carry to 1.
*/

int8_t	op_add(t_corewar *cor)
{
	cor->cur_arg[2]->(*ptr) = cor->cur_arg[0]->(*ptr) + cor->cur_arg[1]->(*ptr);
	if (cor->cur_arg[2]->(*ptr) == 0)
		cor->carry = 1;
	return (SUCCESS);

