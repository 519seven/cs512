all: pa-7.bin

pa-7.bin: main.o
	g++ -Wall -o pa-7.bin main.o

main.o: main.cpp orderedArrayListType.h arrayListType.h
	g++ -Wall -c -g main.cpp

clean:
	rm *.bin *.o