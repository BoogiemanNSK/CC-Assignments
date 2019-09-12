CC = clang++

all: build

build:
	@echo "RUNNING BUILD..."
	@$(CC) -w main.cpp
	@echo "DONE."

test: build
	@echo "RUNNING ON test.cpp NOW..."
	@./a.out test.cpp

testwin: build
	@echo "RUNNING ON test.cpp NOW..."
	@./a.exe test.cpp