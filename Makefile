# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:16:59 by yzaytoun          #+#    #+#              #
#    Updated: 2022/11/02 21:07:52by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex.a

vpath %.c src
vpath %.h include
vpath %_bonus.c bonus
vpath %.o obj


# ************************ Colors ***********************************
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

# --------------------- Definitions ------------------------------------
CC = gcc 
AR = ar
ARFLAGS = -rcs
INC = include
CFLAGS = -Wall -Wextra -Werror -I $(INC) -g3
RM = rm -fr
SANITIAZE = -fsanitize=address -g3
PIPEXBONUS := .
# ------------------ Libft and printf ------------------------------
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a

# ------------------------ Pipex ------------------------------
SRC = get_next_line.c get_next_line_utils.c pipe_com.c pipex_IO.c pipex_aux.c\
		pipex_free.c pipex_list.c pipex_util.c pipex_string.c
BONUS = heredoc_bonus.c pipes_aux_bonus.c pipex_free_bonus.c
OBJDIR = obj

PIP_OBJ := $(SRC:%.c=$(OBJDIR)/%.o)
PIP_OBJB := $(BONUS:%.c=$(OBJDIR)/%.o)


$(OBJDIR)/%.o:%.c
	@mkdir -p $(@D)
	$(COMPILE.c) -o $@ $<


all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(PIP_OBJ) $(OBJDIR)
	@echo "$(YELLOW)Compiling" $@
	@$(AR) $(ARFLAGS) $@ $(PIP_OBJ)
	@echo "$(GREEN)Done!!"
	@$(CC) $(NAME) $(LIBFT) $(PRINTF) main.c -o pipex
	@chmod +x pipex
	@echo "$(YELLOW)************Pipex Mandatory ready****************\n"

$(PRINTF) $(LIBFT) &:
	@echo "$(YELLOW)Making Libft"
	@$(MAKE) -C libft
	@echo "$(YELLOW)Making ft_printf"
	@$(MAKE) -C ft_printf
	@echo "$(GREEN)Finished!!!"

bonus: $(PIPEXBONUS)

$(PIPEXBONUS): $(LIBFT) $(PRINTF) $(PIP_OBJ) $(PIP_OBJB)
	@echo "$(YELLOW)Doing Bonus part....."
	@$(AR) $(ARFLAGS) $(NAME) $(PIP_OBJ) $(PIP_OBJB)
	@$(CC) $(NAME) $(LIBFT) $(PRINTF) main_bonus.c -o pipex
	@chmod +x pipex
	@echo "$(GREEN)\n************Pipex bonus is ready****************\n"


fclean: clean
	@$(RM) $(NAME) pipex

clean:
	@echo "$(RED)Cleaning libft and ft_printf"
	@(cd libft; make fclean)
	@(cd ft_printf; make fclean)
	@echo "Cleaning Object files"
	@$(RM) $(PIP_OBJ) $(PIP_OBJB)
	@echo "Cleaning pipex and pipex.a"
	@$(RM) $(OBJDIR)
	@echo "$(DONE)\n*****************DONE Cleaning**********************\n\n"

re: fclean bonus all

.PHONY: re all bonus fclean clean