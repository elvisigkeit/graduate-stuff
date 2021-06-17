# Prof. and Autora: Silvana Rossetto
# Aluno: Elvis Nobrega
#------------------------------------------------------------

VERSION = 0.1

SERVER = server.c
CLIENT = client.c
SRV = server
CLI = client

#-------------------------------------------------------------
# the rest of the file should not change
INC = ../include
SRC = ../src
OBJ = ../obj
BIN = ../bin

CC = gcc -Wall
CFLAGS = -I$(INC) 
LFLAGS = -lpthread 
RM = rm

# make all
all:  $(OBJ)/mysocket.o $(BIN)/$(SRV) $(BIN)/$(CLI) 

$(OBJ)/mysocket.o: $(SRC)/mysocket.c $(INC)/mysocket.h
	$(CC) -c $(CFLAGS) -o $@ $(SRC)/mysocket.c

$(BIN)/$(SRV): $(OBJ)/mysocket.o $(SERVER)
	$(CC) $(CFLAGS) -o $@ $(OBJ)/mysocket.o $(SERVER) $(LFLAGS) 

$(BIN)/$(CLI): $(OBJ)/mysocket.o $(CLIENT)
	$(CC) $(CFLAGS) -o $@ $(OBJ)/mysocket.o $(CLIENT)
# version
version: 
	@echo $(VERSION) 
# clean
clean:
	$(RM) -rf $(OBJ)/*.o  $(BIN)/*
