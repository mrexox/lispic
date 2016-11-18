CC = g++
EXE = reader
KEYS = -W -g
HEADERS_DIR = ./headers
SRC_DIR = ./src
OBJ_DIR = ./obj

reader: read.o $(SRC_DIR)/main.cpp 
	$(CC) $(OBJ_DIR)/read.o $(SRC_DIR)/main.cpp $(KEYS) -o $(EXE) -I$(HEADERS_DIR)

read.o: $(SRC_DIR)/read.cpp $(HEADERS_DIR)/read.h
	$(CC) $(KEYS) -o $(OBJ_DIR)/read.o -c $(SRC_DIR)/read.cpp -I$(SRC_DIR) -I$(HEADERS_DIR)
