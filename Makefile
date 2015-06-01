#####################################
#   Antoine BLANC - Quentin FAURE   #
#  Sara OUNISSI - Adrien SIPASSEUTH #
#              Sun BIN              #
#               RICM 3              #
#####################################

CC = gcc
CFLAGS = -Wall

SRC = ./src
BIN = ./bin
OBJ = ./obj
LIB = ./lib
INC = ./include

TO_CLEAN = $(OBJ)/*

all: main

$(OBJ)/%.o: $(SRC)/%.c $(INC)/%.h
	@- mkdir -p $(OBJ)
	$(CC) -c $< -o $@ $(CFLAGS) -I $(INC)

$(OBJ)/%.o: $(SRC)/%.c
	@- mkdir -p $(OBJ)
	$(CC) -c $< -o $@ $(CFLAGS) -I $(INC)

main: $(OBJ)/main.o $(OBJ)/dico.o $(OBJ)/data.o $(OBJ)/rwbin.o
	@- mkdir -p $(BIN)
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

clean:
	@rm -rf $(TO_CLEAN)

clean_all: clean
	@rm -rf $(BIN)/* $(TO_CLEAN)
