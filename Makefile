NAME= push_swap
BNS_NAME= push_swap_bonus

SRC= ./Mandatory/push_swap.c ./lib/function_from_lib/ft_atoi.c ./lib/function_from_lib/ft_isdigit.c \
	./lib/function_from_lib/ft_calloc.c ./lib/function_from_lib/ft_bzero.c ./lib/function_from_lib/ft_itoa.c \
	./lib/function_from_lib/ft_lstadd_back.c ./lib/function_from_lib/ft_lstadd_front.c ./lib/function_from_lib/ft_lstclear.c \
	./lib/function_from_lib/ft_lstdelone.c ./lib/function_from_lib/ft_lstiter.c ./lib/function_from_lib/ft_lstlast.c \
	./lib/function_from_lib/ft_lstmap.c ./lib/function_from_lib/ft_lstnew.c ./lib/function_from_lib/ft_lstsize.c \
	./lib/function_from_lib/ft_putchar.c ./lib/function_from_lib/ft_putstr.c ./lib/function_from_lib/ft_split.c \
	./lib/function_from_lib/ft_strnstr.c ./lib/get_next_line/get_next_line.c ./lib/get_next_line/get_next_line_utils.c \
	./Mandatory/functions/pa.c ./Mandatory/functions/pb.c ./Mandatory/functions/ra.c ./Mandatory/functions/rb.c \
	./Mandatory/functions/rr.c ./Mandatory/functions/rra.c ./Mandatory/functions/rrb.c ./Mandatory/functions/rrr.c \
	./Mandatory/functions/sa.c ./Mandatory/functions/sb.c ./Mandatory/functions/ss.c ./Mandatory/helpers/sort_3.c 


SRC_BNS= ./Bonus/push_swap_bonus.c

SRC_OBJ= $(SRC:.c=.o)

BNS_OBJ= $(SRC_BNS:.c=.o)

CC= CC

FLAGS= -Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(SRC_OBJ) ./Mandatory/push_swap.h
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

Bonus: $(BNS_OBJ)
	$(CC) $(Flags) $(SRC) -o $(BNS_NAME)

clean:
	rm -f $(SRC_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all