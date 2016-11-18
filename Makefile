CC = g++
KEYS = -W


reader: main.cpp read.o read.h stdafx.h
	$(CC) $(KEYS) -o reader read.o main.cpp

read.o: read.cpp
	$(CC) $(KEYS) -c read.cpp
