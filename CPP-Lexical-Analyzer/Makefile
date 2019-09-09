CC = clang++

all: test

build:
	@echo "RUNNING BUILD..."
	@$(CC) -w main.cpp
	@echo "DONE."

test: build
	@echo "RUNNING ON test.cpp NOW..."
	@./a.out test.cpp