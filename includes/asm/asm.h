/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 10:04:30 by ffoissey          #+#    #+#             */
/*   Updated: 2020/01/11 19:51:44 by mybenzar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

typedef struct	s_param
{
	char	*name;
	t_param	*next;
}				t_param;

typedef struct	s_op
{
	char	*name;
	int		nb_param;
	t_param	*param;
	t_op	*next;
}				t_op;

typedef struct	s_action
{
	char		*name;
	t_action	*next;

}				t_action;

typedef struct	s_champion
{
	char		*name;
	char		*comment;
	t_action	*actions;
}				t_champion;

#endif
