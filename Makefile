NAME = AA

SRCS = main.cpp
OBJS = $(SRCS:%.cpp=%.o)

CPP = g++ -std=c++17
CPPFLAGS = -Wall -Werror -Wextra
##DFLAG = -g -fsanitize=address
RM = rm -rf
MAKE = make

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(DFLAG) $(CPPFLAGS) $(OBJS) -o $@

$(OBJS): $(SRCS)
	$(CPP) $(DFLAG) $(CPPFLAGS) -c $(SRCS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
