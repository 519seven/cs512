all: pa-4.bin

pa-4.bin: main.o
	g++ -o pa-4.bin main.o

main.o: main.cpp
	g++ -Wall -c -g main.cpp

clean:
	rm *.bin *.o
