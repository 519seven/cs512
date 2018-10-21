all: pa-2.bin

pa-2.bin: main.o unorderedSetTypeImp.o
	g++ -o pa-2.bin main.o unorderedSetTypeImp.o unorderedArrayListTypeImp.o

main.o: main.cpp unorderedArrayListTypeImp.cpp unorderedSetType.h unorderedArrayListType.h
	g++ -Wall -c -g main.cpp unorderedArrayListTypeImp.cpp

unorderedSetTypeImp.o: unorderedSetTypeImp.cpp unorderedSetType.h unorderedArrayListType.h
	g++ -Wall -c -g unorderedSetTypeImp.cpp

clean:
	rm *.bin *.o ._*

