# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = tree

# Source files
SOURCES = main.cpp Complex.cpp

# Header files
HEADERS = Complex.hpp InorderIterator.hpp Node.hpp BfsIterator.hpp KaryTree.hpp \
          PostorderIterator.hpp DfsIterator.hpp PreorderIterator.hpp HeapIterator.hpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)

# Default rule
all: $(TARGET)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS) $(LDFLAGS)

# Compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the project
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET) $(OBJECTS)

.PHONY: all clean run
