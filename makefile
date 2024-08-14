Proj?=concurrency
TARGET=target
SRC=$(wildcard $(Proj)/*.cpp)
OBJ=$(patsubst $(Proj)/%.cpp, $(TARGET)/%.o, $(SRC))
CXX=g++
CXXFLAGS=-std=c++14

.PHONY: $(TARGET)
$(TARGET):
ifeq ($(wildcard $(TARGET)),)
	@mkdir -p $(TARGET)
endif

build: $(TARGET) $(OBJ)

run: build
	$(CXX) $(CXXFLAGS) $(OBJ) -o entry
	./entry

$(TARGET)/%.o:$(Proj)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY:clean
clean:
	rm -rf $(TARGET) entry