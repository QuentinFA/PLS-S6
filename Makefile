#####################################
#   Antoine BLANC - Quentin FAURE   #
# Sara OOUNISSI - Adrien SIPASSEUTH #
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

TO_CLEAN = $(BIN)/* $(OBJ)/*

all: main

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) -c $< -o $@ $(CFLAGS) -I $(INC)

main: $(OBJ)/main.o
	$(CC) $(CFLAGS) -o $(BIN)/$@ $^

clean:
	@rm -rf $(TO_CLEAN)

.PHONY: clean