CC = g++
OUT = lispic
INC = ./include
CFLAGS = -Wall -g -std=c++11 -I$(INC)
SRC = ./src



main.o: evaluator.o reader.o $(SRC)/main.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/main.cpp -o main.o 

reader.o: $(INC)/reader.h $(SRC)/reader.cpp
	$(CC) $(CFLAGS) -c $(SRC)/reader.cpp -o reader.o

repository.o: $(INC)/repository.h $(SRC)/repository.cpp lib.o
	$(CC) $(CFLAGS) -c $(SRC)/repository.cpp -o repository.o

lib.o: $(INC)/lib.h $(SRC)/lib.cpp
	$(CC) $(CFLAGS) -c $(SRC)/lib.cpp -o lib.o

evaluator.o: $(INC)/evaluator.h $(SRC)/evaluator.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/evaluator.cpp -o evaluator.o

symbol.o: $(INC)/symbol.h $(SRC)/symbol.cpp 
	$(CC) $(CFLAGS) -c $(SRC)/symbol.cpp -o symbol.o

user_func.o: $(INC)/user_func.h $(SRC)/user_func.cpp
	$(CC) $(CFLAGS) -c $(SRC)/user_func.cpp -o user_func.o

lispic: main.o reader.o repository.o lib.o evaluator.o symbol.o user_func.o
	$(CC) $(CFLAGS) -o lispic main.o reader.o repository.o lib.o evaluator.o symbol.o user_func.o

clean:
	rm *~ -f
	rm */*~ -f
	rm *.o
