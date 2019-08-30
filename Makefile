# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffoissey <ffoisssey@student.42.fr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/27 09:14:51 by ffoissey          #+#    #+#              #
#    Updated: 2019/08/30 16:37:12 by mybenzar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
################################                ################################
################################ MAIN VARIABLES ################################
################################                ################################
################################################################################

# Name
COREWAR = corewar
DEBUG_COREWAR = corewar_db
ASM = asm
DEBUG_ASM = asm_db

# Compiler
CC = clang

# Lib
PATH_LIBFT = libft/
LIBFT = $(PATH_LIBFT)libft.a
DEBUG_LIBFT = $(PATH_LIBFT)db_libft.a

# Compiler Flags
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Werror

# Compiler Debug Flags
DBFLAGS += $(CFLAGS)
DBFLAGS += -fsanitize=address,undefined
DBFLAGS += -g3
DBFLAGS += -pedantic

# Debug Dir
DSYM += $(ASM).dSYM
DSYM += $(DEBUG_ASM).dSYM
DSYM += $(DEBUG_COREWAR).dSYM
DSYM += $(DEBUG_COREWAR).dSYM

################################################################################
################################                ################################
################################   PRINT VAR    ################################
################################                ################################
################################################################################

# Reset
NC = \033[0m

# Regular Colors
BLACK = \033[0;30m
RED = \033[0;31m
GREEN = \033[32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
PURPLE = \033[0;35m
CYAN = \033[0;36m
WHITE = \033[0;37m

# One Line Output
ONELINE =\e[1A\r

################################################################################
#################################               ################################
#################################    INCLUDES   ################################
#################################               ################################
################################################################################

INCLUDES_LIBFT = libft/includes/
INCLUDES_COMMON = includes/
INCLUDES_COMMON = includes/common/
INCLUDES_COREWAR = includes/corewar/
INCLUDES_ASM = includes/asm/

I_INCLUDES_COREWAR += -I $(INCLUDES_LIBFT)
I_INCLUDES_COREWAR += -I $(INCLUDES_COMMON)
I_INCLUDES_COREWAR += -I $(INCLUDES_COREWAR)
I_INCLUDES_ASM += -I $(INCLUDES_LIBFT)
I_INCLUDES_ASM += -I $(INCLUDES_COMMON)
I_INCLUDES_ASM += -I $(INCLUDES_ASM)

################################################################################
#################################               ################################
#################################    HEADERS    ################################
#################################               ################################
################################################################################

# corewar
HEADER_COREWAR += libft/includes/libft.h
HEADER_COREWAR += includes/common/op.h
HEADER_COREWAR += includes/corewar/corewar.h

# asm
HEADER_ASM += libft/includes/libft.h
HEADER_ASM += includes/common/op.h
HEADER_COREWAR += includes/asm/asm.h

################################################################################
#################################               ################################
#################################  PATH SOURCES ################################
#################################               ################################
################################################################################

PATH_SRCS_COREWAR += srcs/corewar/
PATH_SRCS_COREWAR += srcs/corewar/libop/
PATH_SRCS_ASM += srcs/asm/

################################################################################
#################################               ################################
#################################    SOURCES    ################################
#################################               ################################
################################################################################

# ---------------------------------- corewar --------------------------------- #

SRCS_COREWAR += main_corewar.c
SRCS_COREWAR += init_champion.c
SRCS_COREWAR += load_champion.c
SRCS_COREWAR += game_loop.c

# operation functions

SRCS_COREWAR += op_live.c
SRCS_COREWAR += op_add.c
SRCS_COREWAR += op_sub.c
SRCS_COREWAR += op_ld.c
SRCS_COREWAR += op_ldi.c
SRCS_COREWAR += op_st.c
SRCS_COREWAR += op_sti.c
SRCS_COREWAR += op_and.c
SRCS_COREWAR += op_or.c
SRCS_COREWAR += op_xor.c
SRCS_COREWAR += op_zjmp.c
SRCS_COREWAR += op_aff.c
SRCS_COREWAR += write_to_memory.c

# ------------------------------------ asm ----------------------------------- #

SRCS_ASM += main_asm.c

################################################################################
#################################               ################################
#################################     OBJS      ################################
#################################               ################################
################################################################################

PATH_OBJS_COREWAR = objs/corewar/
OBJS_COREWAR = $(patsubst %.c, $(PATH_OBJS_COREWAR)%.o, $(SRCS_COREWAR))
DEBUG_PATH_OBJS_COREWAR = objs_debug/corewar/
DEBUG_OBJS_COREWAR = $(patsubst %.c, $(DEBUG_PATH_OBJS_COREWAR)%.o, $(SRCS_COREWAR))

PATH_OBJS_ASM = objs/asm/
OBJS_ASM = $(patsubst %.c, $(PATH_OBJS_ASM)%.o, $(SRCS_ASM))
DEBUG_PATH_OBJS_ASM = objs_debug/asm/
DEBUG_OBJS_ASM = $(patsubst %.c, $(DEBUG_PATH_OBJS_ASM)%.o, $(SRCS_ASM))


################# ATTRIBUTION

vpath %.c $(PATH_SRCS_COREWAR)
vpath %.c $(PATH_SRCS_ASM)

################################################################################
#################################               ################################
#################################     RULES     ################################
#################################               ################################
################################################################################

#---------------------------------- STANDARD ----------------------------------#

all: $(ASM) $(COREWAR)

$(COREWAR): $(PATH_OBJS_COREWAR) $(LIBFT) $(OBJS_COREWAR)
	$(CC) $(CFLAGS) $(I_INCLUDES_COREWAR) $(OBJS_COREWAR) $(LIBFT) -o $@
	printf "$(GREEN)$@ is ready.\n\n$(NC)"

$(OBJS_COREWAR): $(PATH_OBJS_COREWAR)%.o: %.c $(HEADER_COREWAR) Makefile
	$(CC) $(CFLAGS) $(I_INCLUDES_COREWAR) -c $< -o $@
	printf "$(ONELINE)$(CYAN)Compiling $<"
	printf "                                                            \n$(NC)"

$(ASM): $(PATH_OBJS_ASM) $(LIBFT) $(OBJS_ASM)
	$(CC) $(CFLAGS) $(I_INCLUDES_ASM) $(OBJS_ASM) $(LIBFT) -o $@
	printf "$(GREEN)$@ is ready.\n\n$(NC)"

$(OBJS_ASM): $(PATH_OBJS_ASM)%.o: %.c $(HEADER_ASM) Makefile
	$(CC) $(CFLAGS) $(I_INCLUDES_ASM) -c $< -o $@
	printf "$(ONELINE)$(CYAN)Compiling $<"
	printf "                                                            \n$(NC)"

$(PATH_OBJS_ASM):
	mkdir -p $@

$(PATH_OBJS_COREWAR):
	mkdir -p $@

$(LIBFT): FORCE
	$(MAKE) -C $(PATH_LIBFT)

#------------------------------------ DEBUG -----------------------------------#

debug: $(DEBUG_ASM) $(DEBUG_COREWAR)

$(DEBUG_COREWAR): $(DEBUG_PATH_OBJS_COREWAR) $(DEBUG_LIBFT) $(DEBUG_OBJS_COREWAR)
	$(CC) $(DBFLAGS) $(I_INCLUDES_COREWAR) $(DEBUG_OBJS_COREWAR) $(DEBUG_LIBFT) -o $@
	printf "$(GREEN)$@ is ready.\n\n$(NC)"

$(DEBUG_OBJS_COREWAR): $(DEBUG_PATH_OBJS_COREWAR)%.o: %.c $(HEADER_COREWAR) Makefile
	$(CC) $(DBFLAGS) $(I_INCLUDES_COREWAR) -c $< -o $@
	printf "$(ONELINE)$(PURPLE)Compiling for DEBUG $<"
	printf "                                                            \n$(NC)"

$(DEBUG_ASM): $(DEBUG_PATH_OBJS_ASM) $(DEBUG_LIBFT) $(DEBUG_OBJS_ASM)
	$(CC) $(DBFLAGS) $(I_INCLUDES_ASM) $(DEBUG_OBJS_ASM) $(DEBUG_LIBFT) -o $@
	printf "$(GREEN)$@ is ready.\n\n$(NC)"

$(DEBUG_OBJS_ASM): $(DEBUG_PATH_OBJS_ASM)%.o: %.c $(HEADER_ASM) Makefile
	$(CC) $(DBFLAGS) $(I_INCLUDES_ASM) -c $< -o $@
	printf "$(ONELINE)$(PURPLE)Compiling for DEBUG $<"
	printf "                                                            \n$(NC)"

$(DEBUG_PATH_OBJS_ASM):
	mkdir -p $@

$(DEBUG_PATH_OBJS_COREWAR):
	mkdir -p $@

$(DEBUG_LIBFT): FORCE
	$(MAKE) -C $(PATH_LIBFT) debug

#--------------------------------- Basic Rules --------------------------------#

clean:
	$(RM) $(OBJS_ASM)
	$(RM) $(DEBUG_OBJS_ASM)
	$(RM) $(OBJS_COREWAR)
	$(RM) $(DEBUG_OBJS_COREWAR)
	$(RM) -R $(PATH_OBJS_ASM)
	$(RM) -R $(DEBUG_PATH_OBJS_ASM)
	$(RM) -R $(PATH_OBJS_COREWAR)
	$(RM) -R $(DEBUG_PATH_OBJS_COREWAR)
	$(RM) -R objs/
	$(RM) -R objs_debug/
	$(RM) -R $(DSYM)
	$(MAKE) -C $(PATH_LIBFT) clean
	printf "$(RED)Objs from corewar and asm removed\n$(NC)"

fclean: clean
	$(RM) $(ASM)
	$(RM) $(DEBUG_ASM)
	$(RM) $(COREWAR)
	$(RM) $(DEBUG_COREWAR)
	$(MAKE) -C $(PATH_LIBFT) fclean
	printf "$(RED)corewar and asm removed\n$(NC)"

re: fclean all

FORCE:

#----------------------------------- Special ----------------------------------#

.PHONY: clean fclean re all debug
#.SILENT:
