all: pa-6.bin

imp: pa-6-imp.bin

pa-6.bin: main.o
	g++ -o pa-6.bin main.o

#main.o: main.cpp unorderedLinkedList.h linkedList.h
#	g++ -Wall -c -g main.cpp

main.o: main.cpp queueADT.h queueAsArray.h
	g++ -Wall -c -g main.cpp

pa-6-imp.bin: main.o unorderedLinkedListImp.o
	g++ -o pa-6.bin main.o

unorderedLinkedListImp.o: unorderedLinkedListImp.cpp linkedList.h unorderedLinkedList.h
	g++ -Wall -c -g unorderedLinkedListImp.cpp

clean:
	rm *.bin *.o ._*