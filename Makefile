NAME		= push_swap
BONUS_NAME	= checker
LIB			= ./lib/ft_printf/libftprintf.a

SRCS		= srcs/main.c \
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
			srcs/operations_two_at_once.c \
			srcs/get_next_line.c

SRCDIR		= srcs/
OBJDIR		= objs/
OBJS		= $(patsubst $(SRCDIR)%.c, $(OBJDIR)%.o, $(SRCS))
DEPS		= $(OBJS:.o=.d)

ifdef BONUS_ON
NAME		= $(BONUS_NAME)
SRCS		= $(BONUS_SRCS)
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
	@printf "\n$(GR)=== Compiled ==="
	@printf "\n--- $(notdir $(SRCS))$(RC)\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	@printf "\n--- $(notdir $(SRCS))$(RC)\n"
	@printf "$(YE)=== Linked [$(CC)] ===\n--- $(NAME)$(RC)\n"

$(LIB) :
	$(MAKE) --no-print-directory -C ./lib/ft_printf

$(OBJDIR) :
	@mkdir -p $(OBJDIR)
	@printf "$(GR)=== Compiling... [$(CC) $(CFLAGS)] ===$(RC)\n"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEAD)
	@printf "$(GR)+$(RC)"

clean :
	$(MAKE) --no-print-directory clean -C ./lib/ft_printf
	$(RM) -r $(OBJDIR)

fclean : clean
	$(MAKE) --no-print-directory fclean -C ./lib/ft_printf
	@printf "$(RE)=== Removing $(NAME) ===$(RC)\n"
	$(RM) $(NAME) $(BONUS_NAME)

re : fclean all

bonus :
	$(MAKE) --no-print-directory BONUS_ON=1

.PHONEY : all clean fclean re bonus

-include $(DEPS)