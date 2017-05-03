.PHONY: all re clean fclean

NAME = ft_db

SRC_PATH = ./src
OBJ_PATH = ./obj

SRC_NAME =	ft_db.c\
			
OBJ_NAME = $(SRC_NAME:.c=.o)
INC_NAME = 	ft_db.h

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(SRC_PATH)/, $(INC_NAME)) 
OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))
LIB = ./src/libftprintf.a

FLAGS = -g#-Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRC) $(LIB) -I $(INC) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
