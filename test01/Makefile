default: test

CC = g++
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

INC_DIRS = -I. -I../include
CXXFLAGS = -g3 -ansi -pedantic -Werror -Wall -DDEBUG -std=c++11 $(INC_DIRS)
LDFLAGS = -g3 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

include depends
depends: 
	$(CC) -MM $(INC_DIRS) $(SOURCES) > depends

$(OBJECTS): $(SOURCES)

test: $(OBJECTS)

test: $(OBJECTS)
	$(CC) $^ $(LDFLAGS) -o $@ 
	# this shit is needed because -l flags must appear after the object files in linking

clean:
	rm test $(OBJECTS) depends

run:
	./test