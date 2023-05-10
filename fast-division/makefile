COMPILER=clang
FLAGS=-O3
FILE=main
EXECUTABLE=fdiv_test

all: assemble compile run

assemble:
	$(COMPILER) $(FLAGS) -S -fverbose-asm $(FILE).c -o ./assembly/$(FILE).s

compile:
	$(COMPILER) $(FLAGS) $(FILE).c -o ./build/$(EXECUTABLE)

run:
	./build/$(EXECUTABLE)

clean:
	rm ./build/$(EXECUTABLE)