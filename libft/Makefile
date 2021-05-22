# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: kfu <kfu@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/14 23:09:58 by kfu           #+#    #+#                  #
#    Updated: 2021/05/05 15:29:57 by kfu           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = 		libft.a
AR =		ar
H_FILES = 	libft.h
CC = 		gcc
RM =		rm -f
CFLAGS = 	-Wall -Wextra -Werror
O_FILES = 	$(SRC:.c=.o)
SRC = 		ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c\
			ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c\
			ft_itoa.c ft_memccpy.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_memchr.c ft_memset.c ft_putchar_fd.c\
			ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c\
			ft_strchr.c ft_strrchr.c ft_strdup.c ft_strjoin.c\
			ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
			ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c\
			ft_atof.c ft_free_split.c ft_strcmp.c ft_strncmp_rev.c\
			ft_tolower.c ft_toupper.c ft_split_words.c\
			ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c\
			ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c\
			ft_lstmap.c

all: $(NAME)

$(NAME): $(O_FILES)
	$(AR) rcs $(NAME) $(O_FILES)

%.o: %.c $(H_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(O_FILES)

fclean: clean
	$(RM) $(NAME)

re: fclean all
