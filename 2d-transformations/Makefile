# Compiler and compiler flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Source files and object files
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

# Target binary
TARGET = my_program

# Default target
all: $(TARGET)

# Rule to build the binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean rule to remove object files and the binary
clean:
	rm -f $(OBJS) $(TARGET)

# Phony target to prevent conflicts with filenames
.PHONY: all clean
