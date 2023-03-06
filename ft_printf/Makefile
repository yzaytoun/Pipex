# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/25 07:58:50 by yzaytoun          #+#    #+#              #
#    Updated: 2023/02/28 19:05:42 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDE = include

vpath %.c src
vpath %_bonus.c bonus 
vpath %.h include
vpath %.o obj

SRC_DIR = ft_format.c ft_hex.c ft_isflag.c ft_printf.c ft_putchar.c ft_putnbr.c\
	     ft_putstr.c
BONUS_DIR =	ft_check_flag_bonus.c ft_flag_combination_bonus.c ft_format_bonus.c\
            ft_isformat_bonus.c ft_putchar_bonus.c ft_reset_flag_bonus.c\
			ft_count_digit_bonus.c ft_flag_precision_bonus.c\
			ft_get_precision_num_bonus.c ft_isunsigned_bonus.c\
			ft_putnbr_bonus.c ft_unsigned_putnbr_bonus.c ft_flag_0_bonus.c\
            ft_flag_space_bonus.c ft_hex_bonus.c ft_printf_bonus.c\
		    ft_putstr_bonus.c ft_zero_condition_bonus.c
OBJDIR = obj

CC = gcc
RM = rm -fr
AR = ar 
ARFLAGS = rcs
CFLAGS = -Wall -Werror -Wextra -I $(INCLUDE) -g3

OBJ := $(SRC_DIR:%.c=$(OBJDIR)/%.o)
OBJ_BONUS := $(BONUS_DIR:%.c=$(OBJDIR)/%.o)
		
$(OBJDIR)/%.o: %.c
	 @mkdir -p $(@D)
	 @$(COMPILE.c) -o $@ $<

		
all : $(NAME)

$(NAME): $(OBJ) $(OBJ_BONUS)
	@$(AR) $(ARFLAGS) $@ $^

bonus: $(B) $(NAME)

$(B): $(OBJ_BONUS) $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $?
	@ar -d $(NAME) ft_printf.o

test:
	@make re
	@make bonus

main:
	@$(CC) main.c libftprintf.a
	@echo "Done"

fclean: clean
	@/bin/$(RM) $(NAME)

clean:
	@/bin/$(RM) $(OBJ) $(OBJ_BONUS) $(OBJDIR)

re: fclean all

.PHONY: all bonus clean fclean re
