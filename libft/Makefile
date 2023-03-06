NAME = libft.a

SRC = ft_isalpha.c  ft_memcmp.c ft_putendl_fd.c ft_strdup.c ft_strlen.c \
		ft_isascii.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c\
		ft_substr.c ft_bzero.c ft_isdigit.c ft_memmove.c ft_putstr_fd.c\
		ft_strjoin.c ft_strncmp.c ft_tolower.c ft_calloc.c ft_isprint.c\
		ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c\
		ft_isalnum.c ft_itoa.c ft_memchr.c ft_putchar_fd.c ft_strchr.c\
		ft_strlcpy.c ft_strrchr.c ft_strtrim.c ft_atoi.c

BONUS = ft_lstadd_front_bonus.c ft_lstmap_bonus.c ft_lstclear_bonus.c\
		ft_lstnew_bonus.c ft_lstdelone_bonus.c ft_lstsize_bonus.c\
		ft_lstiter_bonus.c ft_lstadd_back_bonus.c ft_lstlast_bonus.c
CC := gcc
AR := ar 
ARFLAGS := -rcs
INC := libft.h
CFLAGS := -Wall -Werror -Wextra -I $(INC) 
RM := rm -f

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(BONUS:.c=.o)

%.o : %.c; @$(COMPILE.c) -o $@ $<

all: $(NAME)

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $@ $^

bonus: $(B) $(NAME)

$(B): $(OBJ_BONUS) $(OBJ) 
	@$(AR) $(ARFLAGS) $(NAME) $?

fclean: clean
	@/bin/$(RM) $(NAME)

clean:
	@/bin/$(RM) $(OBJ) $(OBJ_BONUS)

re : fclean all bonus
.PHONY: bonus all clean fclean re
