/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 16:17:24 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 16:32:16 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar"

/*
**	--> op_st : store direct - directly transfers register value (stocked in
**	first argument) in the second argument. If the first argument equals 0,
**	carry is set to 1.
*/

int8_t		op_st(t_corewar *cor)
{
	cor->cur_arg[1]->(*ptr) = cor->reg[cor->cur_arg[0]->(*ptr) - 1];
	if (cor->cur_arg[2]->(*ptr) == 0)
		cor->carry = 1;
	return (SUCCESS);
}
