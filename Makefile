CC = g++
OUT = lispic
CFLAGS = -Wall -g -std=c++11
INCLUDE = ./include
SRC = ./src
OBJ = ./obj

lispic: reader.o $(SRC)/main.cpp 
	$(CC) $(CFLAGS) $(OBJ)/read.o $(SRC)/main.cpp  -o $(OUT) -I$(INCLUDE)

reader_test: reader.o reader_test.cpp
	$(CC) $(CFLAGS) $(OBJ)/reader.o -o reader_test -I$(INCLUDE) reader_test.cpp

eval_test: reader.o evaluator.o $(SRC)/eval_test.cpp 
	$(CC) $(CFLAGS) $(OBJ)/environment.o $(OBJ)/reader.o $(OBJ)/evaluator.o -o eval_test -I$(INCLUDE) $(SRC)/eval_test.cpp

evaluator.o: environment.o $(SRC)/evaluator.cpp $(INCLUDE)/evaluator.h $(INCLUDE)/stdafx.h
	$(CC) $(CFLAGS) -o $(OBJ)/evaluator.o  -c $(SRC)/evaluator.cpp  -I$(INCLUDE)

environment.o: $(INCLUDE)/environment.h $(SRC)/environment.cpp $(INCLUDE)/stdafx.h 
	$(CC) $(CFLAGS) -o $(OBJ)/environment.o -c $(SRC)/environment.cpp -I$(INCLUDE)

reader.o: $(SRC)/reader.cpp $(INCLUDE)/reader.h $(INCLUDE)/stdafx.h
	$(CC) $(CFLAGS) -o $(OBJ)/reader.o -c $(SRC)/reader.cpp -I$(INCLUDE)

clear:
	find . -name *~ -exec rm '{}' +
