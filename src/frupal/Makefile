EXE="../../build/frupal.cgi"

.PHONY: all run build clean

all: clean build run

run: $(EXE)
	./$(EXE)

build: $(EXE)

$(EXE): game.cpp map.cpp player.cpp cgiReader.cpp grovnick.cpp
	g++ -std=c++11 -static $? -o $(EXE)

clean:
	$(RM) $(EXE)
