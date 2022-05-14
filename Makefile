# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abbahoua <abbahoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/15 23:32:51 by abbahoua          #+#    #+#              #
#    Updated: 2022/04/24 02:45:31 by abbahoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = pushswap_utils.c\
	push_swap.c\
	linked_list.c\
	ft_write.c\
	sort5.c\
	stack_index_array.c\
	moves_sp.c\
	moves_rr.c\
	sort_utils.c\
	sort_more.c\
	sort_more_utils.c\
	ft_split.c\

BONUS_SRC = pushswap_utils.c\
	checker_bonus/bonus_utils.c\
	linked_list.c\
	ft_write.c\
	sort5.c\
	stack_index_array.c\
	moves_sp.c\
	moves_rr.c\
	sort_utils.c\
	sort_more.c\
	sort_more_utils.c\
	ft_split.c\
	get_next_line_bonus/get_next_line_bonus.c\
	checker_bonus/checker_bonus.c\

OBJS = $(SRC.c=.o)

GCC = cc

CFLAG = -Wall -Wextra -Werror

RM = rm -f

NAME = push_swap

BONUS = checker

all : $(NAME)

$(NAME) : $(SRC)
		$(GCC) $(CFLAG) $(SRC) -o $(NAME)

bonus : $(BONUS)

$(BONUS) : $(BONUS_SRC)
		$(GCC) $(CFLAG) $(BONUS_SRC) -o $(BONUS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re