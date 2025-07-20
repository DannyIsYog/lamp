# Compiler
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Iinclude
LDFLAGS = 

# Source files
SRCS = $(wildcard src/*.cpp)

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = MiniAcceleratorSimulator

# Default target
all: $(TARGET)

# Link object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile source files into object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -f $(TARGET) $(OBJS)

# Rebuild project from scratch
rebuild: clean all

.PHONY: all clean rebuild
