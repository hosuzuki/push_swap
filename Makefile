NAME = push_swap
BONUS_NAME = checker
SRC = srcs/main.c \
			srcs/validate_number.c \
			srcs/exit.c \
			srcs/init_stack.c \
			srcs/free.c \
			srcs/pre_sort.c \
			srcs/recorder.c \
			srcs/small_case.c \
			srcs/base_act.c 

#			srcs/search_val.c \
#			srcs/few_args.c \
#			srcs/arg_check.c \
#			srcs/many_args_atob.c \
#			srcs/many_args_btoa.c \
#			srcs/many_args_btoa2.c \
#			srcs/vals.c \
#			srcs/optimize.c \

BONUS_SRC = srcs/checker.c
OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
ifdef BONUS_ON
NAME = $(BONUS_NAME)
SRC = $(BONUS_SRC)
OBJ = $(BONUS_OBJ)
endif

LIB = ./libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror
HEAD = -I ./includes
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) $(LIB) -o $(NAME)

$(LIB) :
	$(MAKE) -C ./libft

.c.o :
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o) $(HEAD) -g

clean :
	$(MAKE) clean -C ./libft
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean : clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all

bonus :
	$(MAKE) BONUS_ON=1

.PHONEY : all clean fclean re bonus
