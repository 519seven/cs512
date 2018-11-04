all: pa-6.bin

imp: pa-6-imp.bin

pa-6.bin: main.o
	g++ -o pa-6.bin main.o

#main.o: main.cpp unorderedLinkedList.h linkedList.h
#	g++ -Wall -c -g main.cpp

main.o: main.cpp queueADT.h queueAsArray.h
	g++ -Wall -c -g main.cpp

pa-6-imp.bin: main.o queueAsArrayImp.o
	g++ -o pa-6-imp.bin main.o queueAsArrayImp.o

queueAsArrayImp.o: queueAsArrayImp.cpp queueAsArray.h queueADT.h
	g++ -Wall -c -g queueAsArrayImp.cpp

clean:
	rm *.bin *.o ._*