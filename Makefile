# Compiler
CXX = C:\msys64\ucrt64\bin\g++.exe

# Common include paths
CXXFLAGS = -Iinclude -Itests -std=c++17

# Build directories
build_debug = build/debug
build_release = build/release

# Source files and object files
SRC = $(wildcard src/*.cpp)
OBJ_DEBUG = $(SRC:src/%.cpp=$(build_debug)/%.o)
OBJ_RELEASE = $(SRC:src/%.cpp=$(build_release)/%.o)
TEST = $(wildcard tests/*.cpp)

# Output executable
TARGET = main.exe

# Default target
all: debug

# Debug build
debug: CXXFLAGS += -g -fdiagnostics-color=always
debug: $(OBJ_DEBUG)
	$(CXX) $(OBJ_DEBUG) -o $(TARGET)

# Release build
release: CXXFLAGS += -O2 -DNDEBUG
release: $(OBJ_RELEASE)
	$(CXX) $(OBJ_RELEASE) -o $(TARGET)

# Object file rule
$(build_debug)/%.o: src/%.cpp
	@mkdir -p $(build_debug)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(build_release)/%.o: src/%.cpp
	@mkdir -p $(build_release)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -rf build *.exe