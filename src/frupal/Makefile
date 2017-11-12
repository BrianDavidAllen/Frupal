BUILD=../../build/

EXE=frupal.cgi

.PHONY: all run build clean

all: clean build run

run: $(BUILD)$(EXE)
	cd $(BUILD) && ./$(EXE)

build: $(BUILD)$(EXE)

$(BUILD)$(EXE): game.cpp logger.cpp map.cpp hero.cpp cgiReader.cpp grovnick.cpp
	g++ -std=c++11 -static $? -o $(BUILD)$(EXE)

clean:
	$(RM) $(BUILD)$(EXE)
