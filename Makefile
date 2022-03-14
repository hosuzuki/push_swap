NAME = push_swap
BONUS_NAME = checker
SRC = srcs/main.c \
			srcs/validate_argv.c \
			srcs/exit.c \
			srcs/init_stack.c \
			srcs/free.c \
			srcs/pre_sort.c \
			srcs/recorder.c \
			srcs/cases_of_algo.c \
			srcs/operations.c \
			srcs/search_val.c \
		 	srcs/sort_stacks.c \
			srcs/sort_stack_b.c \
			srcs/sort_stack_b_utils.c \
			srcs/optimize_cmds.c \
			srcs/print_cmds.c 

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
