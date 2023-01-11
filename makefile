NAME = Car

SRC =   Car.cpp Client.cpp I_Person.cpp I_Printable.cpp I_Transport.cpp Login.cpp main.cpp Seller.cpp UtilChecking.cpp Worker.cpp

SRCDIR = source/

OBJDIR = objects/


OBJ = $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJ) ./header/*.hpp
	g++ -std=c++11 $(FLAGS) $(OBJ) -o $(NAME) -lncurses

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJ) : $(OBJDIR)%.o : $(SRCDIR)%.cpp ./header/*.hpp
	g++ -std=c++11 $(FLAGS) -o $@ -c $< -I ./header

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)