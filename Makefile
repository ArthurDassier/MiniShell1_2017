##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

SRC	=	srcs/brain.c		\

OBJ	=	$(SRC:.c = .o)

NAME	=	mysh

LIB_DIR	=	./lib

MY.H_DIR	=	./include

CC	=	gcc

C_FLAGS	=	-Wall -Wextra

LIB_FLAG	=	-L$(LIB_DIR) -lmy

INCL_FLAG	=	-I$(MY.H_DIR)

all:	$(NAME)

$(NAME):	$(OBJ)
		$(MAKE) -C lib/my
		$(CC) -o $(NAME) $(OBJ) $(C_FLAGS) $(LIB_FLAG) $(INCL_FLAG)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: fclean all re clean
