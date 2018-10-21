all: pa-1.bin

pa-1.bin: main.o orderedArrayListTypeImp.o arrayListTypeImp.o
	g++ -o pa-1.bin main.o orderedArrayListTypeImp.o arrayListTypeImp.o

main.o: main.cpp arrayListTypeImp.cpp orderedArrayListType.h arrayListType.h
	g++ -Wall -c -g main.cpp arrayListTypeImp.cpp

orderedArrayListTypeImp.o: orderedArrayListTypeImp.cpp orderedArrayListType.h arrayListType.h
	g++ -Wall -c -g orderedArrayListTypeImp.cpp

clean:
	rm pa-1.bin main.o orderedArrayListTypeImp.o arrayListTypeImp.o

