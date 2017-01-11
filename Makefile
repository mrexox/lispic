CC = g++
OUT = lispic
INC = ./include
CFLAGS = -Wall -g -std=c++11 -I$(INC)
SRC = ./src
OBJ = ./obj



$(OBJ)/main.o: $(OBJ)/evaluator.o $(OBJ)/reader.o $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o $(OBJ)/main.o 

$(OBJ)/reader.o: $(INC)/reader.h $(SRC)/reader.cpp
	$(CC) $(CFLAGS) -c $(SRC)/reader.cpp -o $(OBJ)/reader.o

$(OBJ)/repository.o: $(INC)/repository.h $(SRC)/repository.cpp $(OBJ)/lib.o
	$(CC) $(CFLAGS) -c $(SRC)/repository.cpp -o $(OBJ)/repository.o

$(OBJ)/lib.o: $(INC)/lib.h $(SRC)/lib.cpp
	$(CC) $(CFLAGS) -c $(SRC)/lib.cpp -o $(OBJ)/lib.o

$(OBJ)/evaluator.o: $(INC)/evaluator.h $(SRC)/evaluator.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/evaluator.cpp -o $(OBJ)/evaluator.o

$(OBJ)/symbol.o: $(INC)/symbol.h $(SRC)/symbol.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/symbol.cpp -o $(OBJ)/symbol.o

$(OBJ)/user_func.o: $(INC)/user_func.h $(SRC)/user_func.cpp
	$(CC) $(CFLAGS) -c $(SRC)/user_func.cpp -o $(OBJ)/user_func.o

lispic: $(OBJ)/main.o $(OBJ)/reader.o $(OBJ)/repository.o $(OBJ)/lib.o $(OBJ)/evaluator.o $(OBJ)/symbol.o $(OBJ)/user_func.o
	$(CC) $(CFLAGS) -o lispic $(OBJ)/main.o $(OBJ)/reader.o $(OBJ)/repository.o $(OBJ)/lib.o $(OBJ)/evaluator.o $(OBJ)/symbol.o $(OBJ)/user_func.o

clear:
	rm *~ -f
	rm */*~ -f
