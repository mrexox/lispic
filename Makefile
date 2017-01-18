INC = ./include
CFLAGS = -Wall -g -std=c++11 -I$(INC)
SRC = ./src

main.o: evaluator.o reader.o $(SRC)/main.cpp 
	g++ $(CFLAGS) -c $(SRC)/main.cpp

reader.o: $(INC)/reader.h $(SRC)/reader.cpp
	g++ $(CFLAGS) -c $(SRC)/reader.cpp

repository.o: $(INC)/repository.h $(SRC)/repository.cpp lib.o
	g++ $(CFLAGS) -c $(SRC)/repository.cpp

lib.o: $(INC)/lib.h $(SRC)/lib.cpp
	g++ $(CFLAGS) -c $(SRC)/lib.cpp

evaluator.o: $(INC)/evaluator.h $(SRC)/evaluator.cpp 
	g++ $(CFLAGS) -c $(SRC)/evaluator.cpp

symbol.o: $(INC)/symbol.h $(SRC)/symbol.cpp 
	g++ $(CFLAGS) -c $(SRC)/symbol.cpp

user_func.o: $(INC)/user_func.h $(SRC)/user_func.cpp
	g++ $(CFLAGS) -c $(SRC)/user_func.cpp

lispic: main.o reader.o repository.o lib.o evaluator.o symbol.o user_func.o
	g++ $(CFLAGS) -o lispic main.o reader.o repository.o lib.o evaluator.o symbol.o user_func.o

clean:
	rm *~ -f
	rm */*~ -f
	rm *.o
