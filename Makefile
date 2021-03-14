##
## File name :
## Makefile
## File creator :
## Adrien Colombier
##

CC	=	g++

SRC	=	source/main.cpp

OBJECTS =	${SRC:.cpp=.o}

NAME	=	a.out

CFLAGS	+=	-Wall -Wextra -pedantic -Ofast -I ./lib/cpp-ui -I./include

LDFLAGS	+=	-L./lib/cpp-ui -lcpp-ui -lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio

all:	${NAME}

%.o:	%.cpp
	@echo -e "\e[0;94mCompiled\t\e[0;95m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@${CC} -c ${CFLAGS} $< -o $@

${NAME}:	${OBJECTS}
	@make -C lib/cpp-ui --no-print-directory
	@${CC} -o ${NAME} ${OBJECTS} ${LDFLAGS}
	@echo -e "\e[0;92mDone ${NAME}\e[0m"

clean:
	@make clean -C lib/cpp-ui --no-print-directory
	@rm -f ${OBJECTS}
	@echo -e "\e[38;5;208mObjects:\e[38;5;124m\tDeleted\e[0m"

fclean:	clean
	@make fclean -C lib/cpp-ui --no-print-directory
	@rm -f ${NAME}
	@echo -e "\e[0;92mExecutable:\e[38;5;124m\tDeleted\e[0m"

re:	fclean all

.PHONY:	all clean fclean re