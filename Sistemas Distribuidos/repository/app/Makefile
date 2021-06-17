# Prof. e Autora: Silvana Rossetto
# Aluno: Elvis Nobrega
#------------------------------------------------------------

VERSION = 0.2

PUBLISHER = pub.c
SUBSCRIBER = sub.c
PUB = pub
SUB = sub

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
all:  $(OBJ)/mysocket.o $(BIN)/$(PUB) $(BIN)/$(SUB) 

$(OBJ)/mysocket.o: $(SRC)/mysocket.c $(INC)/mysocket.h
	$(CC) -c $(CFLAGS) -o $@ $(SRC)/mysocket.c

$(BIN)/$(PUB): $(OBJ)/mysocket.o $(PUBLISHER)
	$(CC) $(CFLAGS) -o $@ $(OBJ)/mysocket.o $(PUBLISHER) $(LFLAGS) 

$(BIN)/$(SUB): $(OBJ)/mysocket.o $(SUBSCRIBER)
	$(CC) $(CFLAGS) -o $@ $(OBJ)/mysocket.o $(SUBSCRIBER)
# version
version: 
	@echo $(VERSION) 
# clean
clean:
	$(RM) -rf $(OBJ)/*.o  $(BIN)/*
