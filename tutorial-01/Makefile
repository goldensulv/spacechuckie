default: 01_hello_SDL
MAIN_SOURCE = 01_hello_SDL.cpp
SOURCES = ltexture.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CPPFLAGS = -w -lSDL2 -lSDL2_image

$(OBJECTS): $(SOURCES)

01_hello_SDL: $(MAIN_SOURCE) $(OBJECTS)
	g++ $^ $(CPPFLAGS) -o $@

clean:
	rm 01_hello_SDL *.o