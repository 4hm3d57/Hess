CXX = g++
CXXFLAGS = -Wall -Wextra -Wswitch-enum -std=c++11 -pedantic -fno-exceptions -fexceptions -ggdb -Wno-unused-parameter

INCLUDE_FILES = -I./include
LIB_FILES = -L./lib

SRC_FILES = src/main.cpp

TARGET = main.exe

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(INCLUDE_FILES) $(LIB_FILES) $(SRC_FILES) -lraylib -lopengl32 -lgdi32 -lwinmm

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
