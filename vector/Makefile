CXX = clang++

CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

SRCS = vector.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = a.out

RM = rm -f

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $<

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re