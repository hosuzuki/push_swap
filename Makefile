NAME		= push_swap
BONUS_NAME	= checker
LIB			= ./lib/ft_printf/libftprintf.a

SRCS			= srcs/main.c \
			srcs/validate_argv.c \
			srcs/init_stack.c \
			srcs/free.c \
			srcs/init_sorted_array.c \
			srcs/init_cmds_array.c \
			srcs/select_algo.c \
			srcs/record_one_cmd.c \
			srcs/operations.c \
			srcs/set_min_max.c \
		 	srcs/sort_stacks.c \
			srcs/sort_stack_b.c \
			srcs/optimize_cmds.c \
			srcs/print_cmds.c \
			srcs/get_next_line.c

BONUS_SRCS	= srcs/checker.c \
			srcs/validate_argv.c \
			srcs/init_stack.c \
			srcs/free.c \
			srcs/init_cmds_array.c \
			srcs/select_algo.c \
			srcs/record_one_cmd.c \
			srcs/operations.c \
			srcs/set_min_max.c \
		 	srcs/sort_stacks.c \
			srcs/sort_stack_b.c \
			srcs/operations_two_at_once.c 

SRCDIR		= srcs/
OBJDIR		= objs/
OBJS		= $(patsubst srcs/%.c, $(OBJDIR)%.o, $(SRCS))
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)
DEPS		= $(OBJS:.o=.d)

ifdef BONUS_ON
NAME		= $(BONUS_NAME)
SRCS		= $(BONUS_SRCS)
OBJS		= $(BONUS_OBJ)
endif


# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -MMD -MP
HEAD	= -I./includes/
RM		= rm -f
ARC		= ar rc
RAN		= ranlib

GR		= \033[32;1m
RE		= \033[31;1m
YE		= \033[33;1m
CY		= \033[36;1m
RC		= \033[0m

# **************************************************************************** #

all : $(NAME)

$(NAME) : $(LIB) $(OBJDIR) $(OBJS)
	@printf "\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@printf "$(GR)=== Compiled ==="
	@printf "\n--- $(notdir $(SRCS))$(RC)\n"
	@printf "$(YE)=== Linked [$(CC)] ===\n--- $(NAME)$(RC)\n"

$(LIB) :
	$(MAKE) --no-print-directory -C ./lib/ft_printf

$(OBJDIR) :
	@mkdir -p $(OBJDIR)
	@printf "$(GR)=== Compiling $(NAME) ... [$(CC) $(CFLAGS)] ===$(RC)\n"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEAD)
	@printf "$(GR)+$(RC)"

clean :
	$(MAKE) --no-print-directory clean -C ./lib/ft_printf
	$(RM) -r $(OBJDIR)

fclean : clean
	$(MAKE) --no-print-directory fclean -C ./lib/ft_printf
	$(RM) $(NAME) $(BONUS_NAME)
	@printf "$(RE)=== Removed ===\n--- $(C_NAME), $(S_NAME)$(RC)\n"

re : fclean all

bonus :
	$(MAKE) BONUS_ON=1

.PHONEY : all clean fclean re bonus

-include $(DEPS)