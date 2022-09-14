# CC = gcc

# CFLAGS = -Wall -Wextra -Werror -g

# NAME = push_swap

# SRC = swap.c \
# crea_list.c \
# sort.c \
# help.c \
# help_2.c \
# step.c \
# second_step.c \
# chg_lst.c \
# step_3.c \
# print_and_exit.c \
# print_and_exit_2.c \
# oth_main.c \
# lst_return.c

# SRC_PUSH = main.c \

# SRC_CHECKER = main_bonus.c \

# OBJ = $(SRC:.c=.o)

# OBJ_PUSH = $(SRC_PUSH:.c=.o)

# OBJ_CHECKER = $(SRC_CHECKER:.c=.o)

# RM = rm -f

# %.o : %.c
# 		$(CC) -o $@ -c $< $(CFLAGS)
		
# $(NAME)	:	$(OBJ) $(OBJ_PUSH)
# 		$(MAKE) -C ./libft
# 		cp libft/libft.a $(NAME)
# 		$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_PUSH) libft/libft.a

# bonus 	:	$(OBJ) $(OBJ_CHECKER)
# 			$(MAKE) -C ./libft
# 			cp libft/libft.a $(NAME)
# 			$(MAKE) -C ./gnl
# 			cp gnl/gnl.a $(NAME)
# 			$(CC) $(CFLAGS) -o checker $(OBJ) $(OBJ_CHECKER) libft/libft.a gnl/gnl.a

# all : $(NAME)

# clean :
# 		$(MAKE) clean -C ./libft
# 		$(MAKE) clean -C ./gnl
# 		$(RM) $(OBJ)

# fclean : clean
# 		$(MAKE) fclean -C ./libft
# 		$(MAKE) fclean -C ./gnl
# 		$(RM) $(NAME)

# re : fclean all

# .PHONY : all clean fclean re bonus

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hadufer <hadufer@student.42nice.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 13:33:44 by hadufer           #+#    #+#              #
#    Updated: 2021/11/16 10:37:30 by hadufer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SRCS = swap.c \
crea_list.c \
sort.c \
help.c \
help_2.c \
step.c \
second_step.c \
chg_lst.c \
step_3.c \
print_and_exit.c \
print_and_exit_2.c \
oth_main.c \
lst_return.c


SRCS_PUSH_SWAP = main.c \

SRCS_CHECKER = main_bonus.c \

OBJS = $(SRCS:.c=.o)

OBJS_CHECKER = $(SRCS_CHECKER:.c=.o)

OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -I/usr/include -I./Libft/. -I./gnl/. -c $< -o $@

all:
	@${MAKE} --no-print-directory $(NAME)

$(NAME): $(OBJS) $(OBJS_PUSH_SWAP) ./Libft/libft.a
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_PUSH_SWAP) ./Libft/libft.a -o $(NAME)

bonus:
	@${MAKE} --no-print-directory checker

checker: $(OBJS) $(OBJS_CHECKER) ./Libft/libft.a ./gnl/gnl.a
	$(CC) $(CFLAGS) $(OBJS) $(OBJS_CHECKER) ./gnl/gnl.a ./Libft/libft.a -o checker

./Libft/libft.a:
	$(MAKE) -C ./Libft bonus

./gnl/gnl.a:
	$(MAKE) -C ./gnl

clean:
	$(MAKE) -C ./Libft $@
	$(MAKE) -C ./gnl $@
	$(RM) $(OBJS) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP)

fclean: clean
	$(MAKE) -C ./Libft $@
	$(MAKE) -C ./gnl $@
	$(RM) $(NAME) checker

re: fclean all

.PHONY: all clean flcean re bonus