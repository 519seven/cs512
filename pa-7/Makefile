all: pa-7.bin

pa-7.bin: main.o unorderedArrayListTypeImp.o
	g++ -Wall -o pa-7.bin main.o unorderedArrayListTypeImp.o

main.o: main.cpp unorderedArrayListType.h
	g++ -Wall -c main.cpp

unorderedArrayListTypeImp.o: unorderedArrayListTypeImp.cpp unorderedArrayListType.h arrayListType.h
	g++ -Wall -o unorderedArrayListTypeImp.o unorderedArrayListTypeImp.cpp

clean:
	rm *.bin *.o