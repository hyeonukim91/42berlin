CFILES = ft_printf.c ft_print_char.c ft_print_nbr.c ft_print_hex.c

# a form of pattern substitution in Make, .c -> .o
OFILES = $(CFILES:.c=.o)

#the name of the final file we want to create
NAME = libftprintf.a

CC = cc

# complie flags
CFLAGS = -Wall -Wextra -Werror

#all - firstly generate the library and then clean ofiles
all: $(NAME)

# generate a static library using ofiles
$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES) 

# The rule %.o: %.c means that any .c file can be compiled into a .o file 
# using the command in the body of the rule.
# $< Refers to the first prerequisite (the .c file) 
# $@: Refers to the target file (the .o file).

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OFILES): $(CFILES) ft_printf.h


clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

# rebuild delete all .o files, start complining
re: fclean $(NAME)

.PHONY: all clean fclean re
