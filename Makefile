# =============================================================================
# Banana
# =============================================================================

CXX := clang++

TARGET := build/banana

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:src/%.cpp=build/%.o)
DEP := $(OBJ:.o=.d)

CPPFLAGS := -Iinclude

CXXFLAGS := \
	-std=c++17 \
	-Wall \
	-Wextra \
	-MMD \
	-MP

LDFLAGS :=
LDLIBS :=


# =============================================================================
# Targets
# =============================================================================

.PHONY: all clean run rebuild

all: $(TARGET)


$(TARGET): $(OBJ)
	@mkdir -p $(dir $@)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@


build/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


-include $(DEP)


run: $(TARGET)
	./$(TARGET)


clean:
	rm -rf build


rebuild: clean all
