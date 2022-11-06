##
## EPITECH PROJECT, 2022
## pts-function
## File description:
## main
##

NAME	=	linked_list

FOLDER	=	src/

SRCS	=	$(FOLDER)main.c \
			$(FOLDER)list.c \
			$(FOLDER)free_list.c \
			$(FOLDER)utils_list.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra -W -Iinclude

CC		=	gcc

RM     =	rm -f

all    :	$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -lm

clean  :	
		$(RM) $(NAME)

fclean :	clean
			$(RM) $(OBJS)
			rm -f *~

re     :	fclean all

.PHONY :	all clean fclean re