CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude

TARGET = banana
SRC = $(wildcard src/*.cpp)
OBJ = $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@

src/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: clean
