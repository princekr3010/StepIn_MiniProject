#Makefile 
PROJECT_NAME = tic-tac-toe.exe
SRC=src/disp_matrix.c src/get_computer_move.c src/get_player_move.c src/init_matrix.c src/check_result.c src/vscomputer.c src/multiplayer.c src/game.c Test/test.c
INC = inc
UNITY = unity
TEST = unity/unity.c

DOCUMENTATION_OUTPUT = documentation/html

all: $(SRC)
		gcc -I $(INC) -I$(UNITY) $(SRC) $(TEST) -o tic-tac-toe.exe

RUN:  $(PROJECT_NAME)
		$(PROJECT_NAME)
		
clean:
		del /q *.exe

doc: 
	make -C ./documentation


