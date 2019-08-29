/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mybenzar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:28:09 by mybenzar          #+#    #+#             */
/*   Updated: 2019/08/29 16:47:14 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar"

/*
**	--> op_sub : arithmetical substraction, substracts the second argument to
**	the first and stocks it in the third argument. If the result is 0, carry
**	is set to 1.
*/

int8_t		op_sub(t_corewar *cor)
{
	cor->cur_arg[2]->(*ptr) = cor->cur_arg[1]->(*ptr) - cor->cur_arg[0]->(*ptr);
	if (cor->cur_arg[2]->(*ptr) == 0)
		cor->carry = 1;
	return (SUCCESS);
}
