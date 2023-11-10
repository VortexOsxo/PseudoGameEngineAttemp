# Compiler and flags
CXX = g++
CXXFLAGS = -Iinclude -Iinclude/SFML -Iinclude/headers

# Debug / fps flags (add -g for debugging symbols)
DEBUG_FLAGS = -DDEBUG -g
FPS_FLAGS = -DFPS -g
LDFLAGS = -Llib
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

SOURCE_DIR = src
SRC = $(wildcard $(SOURCE_DIR)/*.cpp) $(wildcard $(SOURCE_DIR)/**/*.cpp) $(wildcard $(SOURCE_DIR)/**/**/*.cpp) $(wildcard $(SOURCE_DIR)/**/**/**/*.cpp)  $(wildcard $(SOURCE_DIR)/**/**/**/**/*.cpp)  
OBJ_DIR = build
OBJ = $(patsubst $(SOURCE_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Targets
.PHONY: all run clean debug

all: main

main: $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(OBJ_DIR)/%.o: $(SOURCE_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

run: main
	./main

clean:
	rm -rf main $(OBJ_DIR)

debug: CXXFLAGS += $(DEBUG_FLAGS)
debug: all

fps: CXXFLAGS += $(FPS_FLAGS)
fps: all