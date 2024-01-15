CC = g++
CFLAGS = -std=c++11
SRC = main.cpp Book.cpp Person.cpp //list of code files 
BUILD_DIR = build
EXECUTABLE = library_management_system

# List of source code files
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)

# Generate a list of object files based on source files
OBJ_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRC_FILES))

all: $(BUILD_DIR) $(EXECUTABLE)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(EXECUTABLE): $(OBJ_FILES)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR) $(EXECUTABLE)

.PHONY: all clean