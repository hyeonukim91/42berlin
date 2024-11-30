# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hyeonuki <hyeonuki@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/17 20:42:56 by hyeonuki          #+#    #+#              #
#    Updated: 2024/11/23 21:46:18 by hyeonuki         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

CFILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	 ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
	 ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
	 ft_calloc.c ft_strdup.c ft_toupper.c ft_tolower.c \
	 ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	 ft_strnstr.c ft_atoi.c ft_strrchr.c ft_substr.c \
	 ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
	 ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
	 ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

# a form of pattern substitution in Make, .c -> .o
OFILES = ${CFILES:.c=.o}

#the name of the final file we want to create
NAME = libft.a

CC = cc

# complie flags
CFLAGS = -Wall -Wextra -Werror

#all - fistly generate the library and then clean ofiles
all: $(NAME) clean

${NAME}: ${OFILES}
	# generate a static library using ofiles
	ar rcs ${NAME} ${OFILES} 

# The rule %.o: %.c means that any .c file can be compiled into a .o file 
# using the command in the body of the rule.
# $< would be replaced with the name of the .c file, 
# and ${<:.c=.o} would replace the .c with .o for the output file.

%.o: %.c
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${OFILES}: ${CFILES} libft.h


clean:
	rm -f ${OFILES}


fclean: clean
	rm -f ${NAME}


# rebuild delete all .0 files, start complining
re: fclean ${NAME}

.PHONY: all clean fclean re
