.PHONY: clean debug
COMPILER = g++
OUTPUT = main.out

main.out: main.o Star.o
	$(COMPILER) main.o Star.o -o $(OUTPUT) -lsfml-graphics -lsfml-window -lsfml-system -g 

Star.o: Star/Star.cpp
	$(COMPILER) -c Star/Star.cpp

clean:
	rm *.o *.out
