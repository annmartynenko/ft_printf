#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amartyne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/18 12:02:58 by amartyne          #+#    #+#              #
#    Updated: 2018/09/12 19:08:05 by amartyne         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a

SRC = ft_printf.c number.c ft_itoa_base.c ft_putunsnbr.c\
extra_fun.c unicode.c find_flag.c for_flags.c if_flags.c\
ft_putstring.c ft_putnumber.c specifier.c ft_strlen.c if_flags_d.c\
ft_putchar.c ft_putstr.c ft_atoi.c ft_memcpy.c ft_isalpha.c ft_isdigit.c\
ft_strsub.c ft_putnbr.c ft_putchar_fd.c if_flags_ito.c\
valid.c not_spec.c ft_itoa_base_int.c ft_itoa_unslong.c\
ft_itoa_max.c ft_putint.c for_add.c for_p.c

FLAGS = -Wall -Wextra -Werror

OUT = $(SRC:.c=.o)

all: $(NAME)

%o.:%.c $(HDR)
	gcc $(FLAGS) -o $@ $<

$(NAME):
	gcc $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OUT)

clean:
	/bin/rm -f *.o
	/bin/rm -f *~

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all