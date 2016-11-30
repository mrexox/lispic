CC = g++
OUT = lispic
CFLAGS = -Wall -g -std=c++11
INCLUDE_DIR = ./include
SRC_DIR = ./src
OBJ_DIR = ./obj

lispic: read.o $(SRC_DIR)/main.cpp 
	$(CC) $(CFLAGS) $(OBJ_DIR)/read.o $(SRC_DIR)/main.cpp  -o $(OUT) -I$(INCLUDE_DIR)

read.o: $(SRC_DIR)/read.cpp $(INCLUDE_DIR)/read.h
	$(CC) $(CFLAGS) -o $(OBJ_DIR)/read.o -c $(SRC_DIR)/read.cpp -I$(INCLUDE_DIR)

clear:
	rm -f $(SRC_DIR)/*~
	rm -f $(INCLUDE_DIR)/*~
	rm -f *~
