CC = g++
OUT = lispic
INCLUDE = ./include
CFLAGS = -Wall -g -std=c++11 -I$(INCLUDE)
SRC = ./src
OBJ = ./obj

lispic: main.o

main.o: evaluator.o reader.o $(SRC)/main.cpp 
	$(CC) $(CFLAGS)  -o $(OBJ)/main.o -c $(SRC)/main.cpp 


evaluator.o: symbol.o environments.o $(SRC)/evaluator.cpp $(INCLUDE)/evaluator.h $(INCLUDE)/stdafx.h
	$(CC) $(CFLAGS) -o $(OBJ)/evaluator.o  -c $(SRC)/evaluator.cpp 

environments.o: symbol.o environment.o builtin.o user_function.o $(SRC)/environments.cpp $(INCLUDE)/environments.h
	$(CC) $(CFLAGS) -o $(OBJ)/environments.o -c $(SRC)/environments.cpp

builtin.o: $(SRC)/biltin.cpp $(INCLUDE)/builtin.h $(INCLUDE)/function.h
	$(CC) $(CFLAGS) -o $(OBJ)/builtin.o -c $(SRC)/builtin.cpp

user_function.o:  $(SRC)/user_function.cpp $(INCLUDE)/user_function.h $(INCLUDE)/function.h
	$(CC) $(CFLAGS) -o $(OBJ)/user_function.o -c $(SRC)/user_function.cpp

environment.o: symbol.o $(INCLUDE)/environment.h
	$(CC) $(CFLAGS) -o $(OBJ)/environment.o -c $(INCLUDE)/environment.h

reader.o: symbol.o $(SRC)/reader.cpp $(INCLUDE)/reader.h $(INCLUDE)/stdafx.h
	$(CC) $(CFLAGS) -o $(OBJ)/reader.o -c $(SRC)/reader.cpp

symbol.o: $(INCLUDE)/symbol.h
	$(CC) $(CFLAGS) -o $(OBJ)/symbol.o -c $(SRC)/symbol.cpp 

clear:
	find . -name *~ -exec rm '{}' +
