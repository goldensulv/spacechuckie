default: main
MAIN_SOURCE = main.cpp
SOURCES = Texture.cpp Game.cpp
OBJECTS = $(SOURCES:.cpp=.o)

CPPFLAGS = -w -lSDL2 -lSDL2_image

$(OBJECTS): $(SOURCES)

main: $(MAIN_SOURCE) $(OBJECTS)
	g++ $^ $(CPPFLAGS) -o $@

clean:
	rm main *.o