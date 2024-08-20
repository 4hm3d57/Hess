CXX = g++
CXXFLAGS = -Wall -Wextra -Wswitch-enum -std=c++11 -pedantic -fno-exceptions -fexceptions -ggdb -Wno-unused-parameter -g

INCLUDE_FILES = -I./include
LIB_FILES = -L./lib
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC_FILES = $(wildcard src/*.cpp)
TARGET = hess.exe

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) $(INCLUDE_FILES) -o $(TARGET) $(SRC_FILES) $(LIB_FILES) $(LIBS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
