default: test

CC = g++
MAIN_SOURCE = Main/test.cpp
SOURCES = $(wildcard *.cpp) 
OBJECTS = $(SOURCES:.cpp=.o)

INC_DIRS =  -I.
CPPFLAGS = -g3 -ansi -pedantic -Wall -Werror -DDEBUG -std=c++11 $(INC_DIRS)
CXXFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

$(OBJECTS): $(SOURCES)

test.o: $(MAIN_SOURCE)
	$(CC) $(CPPFLAGS) -c $^
test: $(OBJECTS) test.o
	$(CC) $^ -o $@ $(CXXFLAGS)

clean:
	rm test $(OBJECTS) test.o

run:
	./test