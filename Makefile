# Compiler
CXX = clang++
CXXFLAGS = -Wall -Wextra -std=c++17

# Find all .cpp files
SOURCES = $(shell find . -name '*.cpp')

# Create a list of output executables by replacing .cpp with no extension
EXECUTABLES = $(SOURCES:.cpp=)

# Default target
all: $(EXECUTABLES)

# Rule to compile each .cpp file to an executable
%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# Clean target to remove executables
clean:
	rm -f $(EXECUTABLES)

.PHONY: all clean
