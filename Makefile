NAME_1 = philo_one
NAME_2 = philo_two
NAME_3 = philo_three

OBJECT_1 = ./philo_1/philo_one.o ./philo_1/thread.o ./philo_1/utils1.o\
			./philo_1/utils2.o ./philo_1/write.o

OBJECT_2 = ./philo_2/philo_two.o ./philo_2/thread.o ./philo_2/utils1.o\
			./philo_2/utils2.o ./philo_2/write.o

OBJECT_3 = ./philo_3/philo_three.o ./philo_3/thread.o ./philo_3/utils1.o\
			./philo_3/utils2.o ./philo_3/write.o ./philo_3/tread2.o

HEADER_1 = ./philo_1/
HEADER_2 = ./philo_2/
HEADER_3 = ./philo_3/

DIR_SRC_1 = ./philo_1/
DIR_SRC_2 = ./philo_2/
DIR_SRC_3 = ./philo_3/

DIR_OBJ_1 = ./philo_2/object/
DIR_OBJ_2 = ./philo_2/object/

FLAG = -Wextra -Werror -Wall

all: $(NAME_1) $(NAME_2) $(NAME_3)

$(NAME_1):  $(OBJECT_1)
	@gcc -o $@ $^
	@echo philo_one compilied
%.o: %.c
	@gcc $(FLAG) -I $(HEADER_1) -c $< -o $@
	

$(NAME_2):  $(OBJECT_2)
	@gcc -o $@ $^
	@echo philo_two compilied
%.o: %.c
	@gcc $(FLAG) -I $(HEADER_2) -c $< -o $@

$(NAME_3):  $(OBJECT_3)
	@gcc -o $@ $^
	@echo philo_three compilied
%.o: %.c
	@gcc $(FLAG) -I $(HEADER_3) -c $< -o $@
	
one: $(NAME_1)

two: $(NAME_2)

three: $(NAME_3)

clean:
	@rm -f $(OBJECT_1)
	@rm -f $(OBJECT_2)
	@rm -f $(OBJECT_3)
	@echo objects deleted

fclean: clean
	@rm -f $(NAME_1)
	@rm -f $(NAME_2)
	@rm -f $(NAME_3)
	@echo deleted

re: fclean all

bonus: re

.PHONY: all clean fclean re one two
