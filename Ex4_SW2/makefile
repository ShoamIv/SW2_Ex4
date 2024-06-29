# Variables
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system
TARGET = tree
TEST_EXECUTABLE = run_tests
VALGRIND_FLAGS=--leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --error-exitcode=99
# Header files
HEADERS = Complex.hpp InorderIterator.hpp Node.hpp BfsIterator.hpp KaryTree.hpp \
          PostorderIterator.hpp DfsIterator.hpp PreorderIterator.hpp HeapIterator.hpp

# Source files
SOURCES = main.cpp Complex.cpp

# Test sources (excluding main.cpp)
TEST_SOURCES = Test.cpp TestCounter.cpp

# Object files
OBJECTS = $(SOURCES:.cpp=.o)
TEST_OBJECTS = $(TEST_SOURCES:.cpp=.o)

valgrind_test: $(TEST_EXECUTABLE)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./run_tests 

valgrind_tree: $(TARGET)
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./valgrind_tree	
# Default rule
all: $(TARGET)

# Rule for linking the test executable
$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(filter-out main.o,$(OBJECTS))
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Build the executable
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

# Compile .cpp files to .o files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the project
run: $(TARGET)
	./$(TARGET)

# Run tests rule
test: $(TEST_EXECUTABLE)
	./$(TEST_EXECUTABLE)

# Clean up build files
clean:
	rm -f $(TARGET) $(TEST_EXECUTABLE) $(OBJECTS) $(TEST_OBJECTS)

.PHONY: all clean run test
