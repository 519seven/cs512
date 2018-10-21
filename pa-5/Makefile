all: pa-5.bin

pa-5.bin: main.o
	g++ -o pa-5.bin main.o

main.o: main.cpp unorderedLinkedList.h linkedList.h
	g++ -Wall -c -g main.cpp

unorderedLinkedListImp.o: unorderedLinkedListImp.cpp unorderedLinkedList.h linkedList.h
	g++ -Wall -c -g unorderedLinkedListImp.cpp

clean:
	rm *.bin *.o