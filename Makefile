CC = gcc

all: main
	&{CC} main

main: Bargraph.o Vector.o main.o
	${CC} BarGraph.o Vector.o main.o -o main

main.o: main.c
	${CC} -c main.c

Vector.o: Sources/Vector.c
	${CC} -c Sources/Vector.c Headers/Vector.h

Bargraph.o: Sources/BarGraph.c
	${CC} -c Sources/BarGraph.c Headers/BarGraph.h

clean:
	rm -rf *.o main




#check:
#	echo "Implement check"

#build:
#	ehco "Typo"

#test:
#	echo "Testing"

#CC=g++
#CFLAGS=-c -Wall
#LDFLAGS=
#SOURCES=main.cpp Sources/hello.cpp Sources/factorial.cpp
#OBJECTS=$(SOURCES:.cpp=.o)
#EXECUTABLE=mainexe

#all: $(SOURCES) $(EXECUTABLE)

#$(EXECUTABLE): $(OBJECTS)
#	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

#.cpp.o:
#	$(CC) $(CFLAGS) $< -o $@