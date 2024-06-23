NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra

SOURCES = 0_main.c \
          1_format_args.c \
          1_format_one_arg.c \
          2_arr2circular.c \
          3_push_swap.c \
          4_sort_few.c \
          5_sort_left.c \
          5_sort_right.c \
          funcs_atoi.c \
          funcs_check.c \
          funcs_lens_cpys.c \
          funcs_lsts.c \
          funcs_p_s_r_rr.c \
          funcs_print_push_swap.c \
          funcs_print_rotate_reverse.c \
          funcs_sort_few.c \
          funcs_sort_left.c \
          funcs_sort_right.c \
          funcs_sort_tools.c \
          funcs_split.c \
          test_funcs.c

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(SOURCES)

clean:
	rm -f *.txt

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re