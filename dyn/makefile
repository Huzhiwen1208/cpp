SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
CXX=gcc
CFLAGS=-Wall -Wextra -Werror -g -fPIC -I./include
SO_NAME=Test

run: build
	@echo "Running..."
	$(CXX) main.c -o runner -L. -l$(SO_NAME)
	@./runner
	@echo "Done...."
	@rm -rf $(OBJECTS) lib$(SO_NAME).so runner

build: $(SOURCES)
	$(CXX) $(CFLAGS) -c  $(SOURCES)
	$(CXX) $(OBJECTS) -shared -o lib$(SO_NAME).so
	@rm -rf $(OBJECTS)

clean:
	@rm -rf $(OBJECTS) lib$(SO_NAME).so runner