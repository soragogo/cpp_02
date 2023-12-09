NAME=a.out

CXX=c++

CXXFLAGS=-Wall -Wextra -Werror -std=c++98

SRCS= main.cpp \
	Fixed.cpp

OBJS=$(SRCS:.cpp=.o)

all:$(NAME)

$(NAME):$(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:clean
	rm -rf $(NAME)

re:fclean
	make all
