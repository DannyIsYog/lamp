# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude
LDFLAGS = 

# Source and object files
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = MiniAcceleratorSimulator

# Default rule
all: $(TARGET)

# Linking the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compiling source files to object files
src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleaning up object files and executable
clean:
	rm -f $(TARGET) $(OBJS)

# Complete rebuild
rebuild: clean all

.PHONY: all clean rebuild
