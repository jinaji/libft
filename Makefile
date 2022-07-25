# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 18:15:33 by jinkim2           #+#    #+#              #
#    Updated: 2022/07/25 14:07:17 by jinkim2          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = 	ft_isalpha.c 			\
		ft_isdigit.c 			\
 		ft_isalnum.c 			\
		ft_isascii.c 			\
		ft_isprint.c 			\
		ft_strlen.c  			\
		ft_memset.c  			\
		ft_bzero.c   			\
		ft_memcpy.c  			\
		ft_memmove.c 			\
		ft_strlcpy.c 			\
		ft_strlcat.c 			\
		ft_toupper.c 			\
		ft_tolower.c 			\
		ft_strchr.c 			\
		ft_strrchr.c 			\
		ft_strncmp.c 			\
		ft_memchr.c 			\
		ft_memcmp.c 			\
		ft_strnstr.c 			\
		ft_atoi.c 				\
		ft_calloc.c 			\
		ft_strdup.c 			\
		ft_substr.c 			\
		ft_strjoin.c 			\
		ft_strtrim.c 			\
		ft_split.c 				\
		ft_itoa.c 				\
		ft_strmapi.c 			\
		ft_striteri.c 			\
		ft_putchar_fd.c 		\
		ft_putstr_fd.c 			\
		ft_putendl_fd.c 		\
		ft_putnbr_fd.c			\
		get_next_line.c			\
		get_next_line_utils.c	\
		ft_strndup.c

OBJS = ${SRCS:.c=.o}

SRCS_BONUS = ft_lstnew.c 		\
			ft_lstadd_front.c 	\
			ft_lstsize.c 		\
			ft_lstlast.c 		\
			ft_lstadd_back.c 	\
			ft_lstdelone.c 		\
			ft_lstclear.c 		\
			ft_lstiter.c 		\
			ft_lstmap.c
			
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

NAME = libft.a

ifdef BONUS_CHECK
	OBJ_FILES = ${OBJS} ${OBJS_BONUS}
else
	OBJ_FILES = ${OBJS}
endif 

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	ar crs $(NAME) $^

clean:
	rm -f $(OBJS) ${OBJS_BONUS}

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: ${OBJS_BONUS}
	make BONUS_CHECK=1

.PHONY : all clean fclean re bonus